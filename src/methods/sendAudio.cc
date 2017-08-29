
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendAudio.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendAudio::sendAudio(Chat C, std::string audio) : telegram_methodJSON("sendAudio"), telegram_methodMultipart("sendAudio") , chat_id(to_string(C.getId())), audio(audio)
{

}

sendAudio::sendAudio(int chat_id, std::string audio) : telegram_methodJSON("sendAudio"),telegram_methodMultipart("sendAudio") ,chat_id(to_string(chat_id)) , audio(audio)
{

}

sendAudio::sendAudio(string chat_id, std::string audio) : telegram_methodJSON("sendAudio"),telegram_methodMultipart("sendAudio") ,chat_id(chat_id) , audio(audio)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendAudio::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["audio"] = getAudio();

    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    if(getDuration()){
        Outgoing["duration"] = getDuration().value();
    }
    if(getPerformer()){
        Outgoing["performer"] = getPerformer().value();
    }
    if(getTitle()){
        Outgoing["title"] = getTitle().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}

void sendAudio::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"photo",
                 CURLFORM_FILE,audio.c_str(),
                 CURLFORM_END);
    if(caption){
        curl_formadd(start,end,
                     CURLFORM_COPYNAME,"caption",
                     CURLFORM_COPYCONTENTS,caption.value().c_str(),
                     CURLFORM_END);
    }
    //TODO add other fields
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendAudio::setCaption(const optional<string> &caption) {
    sendAudio::caption = caption;
}


void sendAudio::setDuration(const optional<string> &duration) {
    sendAudio::duration = duration;
}

void sendAudio::setPerformer(const optional<string> &performer) {
    sendAudio::performer = performer;
}

void sendAudio::setTitle(const optional<string> &title) {
    sendAudio::title = title;
}

void sendAudio::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendAudio::disable_notification = disable_notification;
}

void sendAudio::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendAudio::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendAudio::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendAudio::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendAudio::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendAudio::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendAudio::setReplyMarkup(const ForceReply FR){
    sendAudio::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendAudio::getChat_id() const {
    return chat_id;
}

const string &sendAudio::getAudio() const {
    return audio;
}

const optional<string> &sendAudio::getCaption() const {
    return caption;
}

const optional<string> &sendAudio::getDuration() const {
    return duration;
}

const optional<string> &sendAudio::getPerformer() const {
    return performer;
}

const optional<string> &sendAudio::getTitle() const {
    return title;
}

const optional<bool> &sendAudio::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendAudio::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendAudio::getReply_markup() const {
    return reply_markup;
}
