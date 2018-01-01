
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendVideo.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendVideo::sendVideo(Chat C, std::string video) :
        telegram_methodJSON("sendVideo"), telegram_methodMultipart("sendVideo"),
        chat_id(to_string(C.getId())), video(video)
{

}

sendVideo::sendVideo(int chat_id, std::string video) :
        telegram_methodJSON("sendVideo"), telegram_methodMultipart("sendVideo"),
        chat_id(to_string(chat_id)), video(video)
{

}

sendVideo::sendVideo(string chat_id, std::string video) :
        telegram_methodJSON("sendVideo"), telegram_methodMultipart("sendVideo"),
        chat_id(chat_id), video(video)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendVideo::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["video"] = getVideo();

    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    if(getDuration()){
        Outgoing["duration"] = getDuration().value();
    }
    if(getWidth()){
        Outgoing["width"] = getWidth().value();
    }
    if(getHeight()){
        Outgoing["height"] = getHeight().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}

void sendVideo::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"video",
                 CURLFORM_FILE,video.c_str(),
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

void sendVideo::setCaption(const optional<string> &caption) {
    sendVideo::caption = caption;
}


void sendVideo::setDuration(const optional<unsigned int> &duration) {
    sendVideo::duration = duration;
}

void sendVideo::setWidth(const optional<unsigned int> &width) {
    sendVideo::width = width;
}

void sendVideo::setHeight(const optional<unsigned int> &height) {
    sendVideo::height = height;
}

void sendVideo::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendVideo::disable_notification = disable_notification;
}

void sendVideo::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendVideo::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendVideo::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendVideo::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendVideo::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendVideo::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendVideo::setReplyMarkup(const ForceReply FR){
    sendVideo::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendVideo::getChat_id() const {
    return chat_id;
}

const string &sendVideo::getVideo() const {
    return video;
}

const optional<string> &sendVideo::getCaption() const {
    return caption;
}

const optional<unsigned int> &sendVideo::getDuration() const {
    return duration;
}

const optional<unsigned int> &sendVideo::getWidth() const {
    return width;
}

const optional<unsigned int> &sendVideo::getHeight() const {
    return height;
}

const optional<bool> &sendVideo::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendVideo::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendVideo::getReply_markup() const {
    return reply_markup;
}
