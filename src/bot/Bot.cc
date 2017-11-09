//
// Created by norbert on 12.08.17.
//

#include <iostream>
#include <functional>
#include <thread>
#include <condition_variable>
#include <vector>
#include <queue>
#include <curl/curl.h>

#include "exceptions/curl_error.h"
#include "exceptions/telegram_api_error.h"
#include "types/telegram_type.h"
#include "methods/getMe.h"
#include "types/User.h"
#include "types/Update.h"

#include "bot/Bot.h"

#include "methods/sendMessage.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Bot::Bot(Token& T) : token(T), isPolling(false){
//    isPolling=false;
//    cout << T.getToken() << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Util Section                                                                                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Function to join the main threads so cpu load is not 100 % when using this
 * @return
 */
void Bot::join(){
    Polling.join();
    Updating.join();
}

/**
 * String Writeback Method for Curl Related stuff
 * Related: https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html >>
 * This callback function gets called by libcurl as soon as there is data received that needs to be saved
 * the size of that data is size multiplied with nmemb.
 * @param contents the curl values which are received
 * @param size
 * @param nmemb
 * @param stringptr, the user data supplied later in curl settings
 * @return
 */
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *stringptr){
    ((string*)stringptr)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Polling Section                                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Defaults starts with a timeout of 100s
 */
void Bot::startLongPoll() {
    this->startLongPoll(100);
}

void Bot::startLongPoll(long timeout) {
    if(!(timeout <0 || timeout >200)){
        //timeout is out of telegram usable range, 0 for shortpolling
    }
    if(this->isPolling){
        //throw bot is polling
    }
    this->isPolling=true;
    Polling = std::thread(&Bot::LongPolling,this,timeout);
}

void Bot::stopLongPoll() {
    if(!this->isPolling){
        //Bot has already stopped
    }
    this->isPolling=false;
    this->Polling.join();
}

void Bot::LongPolling(long timeout){
    if(!(timeout <0 || timeout >200)){
        //timeout is out of telegram usable range, 0 for shortpolling
    }
//    int retrys_availlable=5;
    CURL* curl = curl_easy_init();
    Json::Reader reader;
    string readBuffer;
    string apiURL("https://api.telegram.org/bot"+token.getToken()+"/getUpdates");
    curl_easy_setopt(curl,CURLOPT_URL,apiURL.c_str());
    curl_easy_setopt(curl,CURLOPT_TIMEOUT, timeout);//100 sekunden?
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,&readBuffer);
    CURLcode res = CURLE_OK;
    Update last(0);//Latest Dummy Update
    do{
        string offset("timeout="+to_string(timeout)+"&offset="+to_string(last.getUpdate_id()+1));// No NEed to get them again
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,offset.c_str());
        res = curl_easy_perform(curl);
        Json::Value Response;
        reader.parse(readBuffer,Response);
        if(Response["ok"].asBool()){
            // parse string, and enque updates
            unique_lock<mutex> lock(m);
            for(int i=0;i<Response["result"].size();i++){
                Json::Value Update_json;
                Update_json = Response["result"][i];
                Update update = fromJson<Update>(Update_json);
                pendingUpdates.push(update);
                pendingUpdatesAvailable.notify_one();
                last = update;
            }
        }
        else{
                cerr << "Response was not ok" << readBuffer << endl;
                curl_easy_cleanup(curl);
                throw telegram_api_error(Response["error_code"].asInt(),Response["description"].asString());
        }
        readBuffer.clear();
        Response.clear();
    }
    while(isPolling && !res);
    if(res != CURLE_OK){
        throw curl_error(res,curl_easy_strerror(res));
//        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    }
    curl_easy_cleanup(curl);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Update Notify Section                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Bot::startUpdating() {
    this->isUpdating=true;
    Updating = std::thread(&Bot::NotifyRegisteredListeners,this);

}

void Bot::stopUpdating() {
    this->isUpdating=false;
    this->Updating.join();
}

void Bot::NotifyRegisteredListeners() {
    //todo not check whom all wants, pre check then notify

    std::unique_lock<std::mutex> lock(m);
    while(isUpdating)
    {
        pendingUpdatesAvailable.wait(lock);
        while(!pendingUpdates.empty()){
//            cout << "Removing From Queue";
            Update U = pendingUpdates.front();
            //On Update Listeners
            for(function<void(Update)> L: OnUpdateListeners){
                L(U);
            }
            //On Message Listeners
            for(function<void(Message)> L: OnMessageListener){
                if(U.getMessage()){
                    L(U.getMessage().value());
                }
            }

            //On Message Edited
            if(U.getEdited_message()){
                for(function<void(Message)> L: OnMessageEditedListener){
                    L(U.getEdited_message().value());
                }
            }
            //On Channel Post
            for(function<void(Message)> L: OnChannelPostListener){
                if(U.getChannel_post()){
                    L(U.getChannel_post().value());
                }
            }
            //On Channel Post Edited
            for(function<void(Message)> L: OnChannelPostEditedListener){
                if(U.getEdited_channel_post()){
                    L(U.getEdited_channel_post().value());
                }
            }
            //On Inline Query
            if(U.getInlineQuery()){
                for(function<void(InlineQuery)> L: OnInlineQueryListener){
                    L(U.getInlineQuery().value());
                }
            }
            pendingUpdates.pop();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Callback Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Bot::addOnUpdateListener(function<void(Update)> Listener) {
    OnUpdateListeners.push_back(Listener);
}
void Bot::addOnMessageBotCommandListener(std::function<void(Message,MessageEntity)> Listener) {
    OnMessageCommandListener.push_back(Listener);
}

void Bot::addOnMessageListener(std::function<void(Message)> Listener) {
    OnMessageListener.push_back(Listener);
}

void Bot::addOnMessageEditedListener(function<void(Message)> Listener) {
    OnMessageEditedListener.push_back(Listener);
}

void Bot::addOnChannelPostListener(function<void(Message)> Listener) {
    OnChannelPostListener.push_back(Listener);
}

void Bot::addOnChannelPostEditedListener(std::function<void(Message)> Listener) {
    OnChannelPostEditedListener.push_back(Listener);
}

void Bot::addOnInlineQueryListener(std::function<void(InlineQuery)> Listener) {
    OnInlineQueryListener.push_back(Listener);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// "Outgoing"  Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const User Bot::getMe() const {
    auto GM = yatbcpp::getMe();
    User u = telegram_methodJSON<User>::perform_requestJSON(token, GM);
    return u;
}


const Message Bot::send(sendMessage sm) const{
    return telegram_methodJSON<Message>::perform_requestJSON(token, sm);
   
}