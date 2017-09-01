
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendVoice.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendVoice::sendVoice(Chat C, std::string voice) :
        telegram_methodJSON("sendVoice"), telegram_methodMultipart("sendVoice"),
        chat_id(to_string(C.getId())), voice(voice)
{

}

sendVoice::sendVoice(int chat_id, std::string voice) :
        telegram_methodJSON("sendVoice"), telegram_methodMultipart("sendVoice"),
        chat_id(to_string(chat_id)), voice(voice)
{

}

sendVoice::sendVoice(string chat_id, std::string voice) :
        telegram_methodJSON("sendVoice"), telegram_methodMultipart("sendVoice"),
        chat_id(chat_id), voice(voice)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendVoice::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["voice"] = getVoice();

    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    if(getDuration()){
        Outgoing["duration"] = getDuration().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}

void sendVoice::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"voice",
                 CURLFORM_FILE,voice.c_str(),
                 CURLFORM_END);
    if(caption){
        curl_formadd(start,end,
                     CURLFORM_COPYNAME,"caption",
                     CURLFORM_COPYCONTENTS,caption.value().c_str(),
                     CURLFORM_END);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendVoice::setCaption(const optional<string> &caption) {
    sendVoice::caption = caption;
}


void sendVoice::setDuration(const optional<string> &duration) {
    sendVoice::duration = duration;
}

void sendVoice::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendVoice::disable_notification = disable_notification;
}

void sendVoice::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendVoice::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendVoice::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendVoice::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendVoice::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendVoice::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendVoice::setReplyMarkup(const ForceReply FR){
    sendVoice::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendVoice::getChat_id() const {
    return chat_id;
}

const string &sendVoice::getVoice() const {
    return voice;
}

const optional<string> &sendVoice::getCaption() const {
    return caption;
}

const optional<string> &sendVoice::getDuration() const {
    return duration;
}

const optional<bool> &sendVoice::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendVoice::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendVoice::getReply_markup() const {
    return reply_markup;
}
