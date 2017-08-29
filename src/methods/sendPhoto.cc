
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <iostream>
#include "methods/sendPhoto.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendPhoto::sendPhoto(Chat C, std::string photo) : telegram_methodJSON("sendPhoto") , telegram_methodMultipart("sendPhoto") , chat_id(to_string(C.getId())), Photo(photo)
{

}

sendPhoto::sendPhoto(int chat_id, std::string photo) : telegram_methodJSON("sendPhoto") , telegram_methodMultipart("sendPhoto") , chat_id(to_string(chat_id)) , Photo(photo)
{

}

sendPhoto::sendPhoto(string chat_id, std::string photo) : telegram_methodJSON("sendPhoto") , telegram_methodMultipart("sendPhoto") , chat_id(chat_id) , Photo(photo)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Json::Value sendPhoto::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["photo"] = getPhoto();

    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}

void sendPhoto::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"photo",
                 CURLFORM_FILE,Photo.c_str(),
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

void sendPhoto::setCaption(const optional<string> &caption) {
    sendPhoto::caption = caption;
}


void sendPhoto::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendPhoto::disable_notification = disable_notification;
}

void sendPhoto::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendPhoto::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendPhoto::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendPhoto::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendPhoto::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendPhoto::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendPhoto::setReplyMarkup(const ForceReply FR){
    sendPhoto::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendPhoto::getChat_id() const {
    return chat_id;
}

const string &sendPhoto::getPhoto() const {
    return Photo;
}

const optional<string> &sendPhoto::getCaption() const {
    return caption;
}


const optional<bool> &sendPhoto::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendPhoto::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendPhoto::getReply_markup() const {
    return reply_markup;
}
