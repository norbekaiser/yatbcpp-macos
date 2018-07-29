
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendDocument.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendDocument::sendDocument(Chat C, string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(to_string(C.getId())), document(move(Document))
{

}

sendDocument::sendDocument(int64_t chat_id, string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(to_string(chat_id)), document(move(Document))
{

}

sendDocument::sendDocument(string chat_id, string Document) :
        telegram_methodJSON("sendDocument"), telegram_methodMultipart("sendDocument"),
        chat_id(move(chat_id)), document(move(Document))
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendDocument::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["document"] = getDocument();

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

void sendDocument::add_to_post(struct curl_httppost **start, struct curl_httppost **end) {
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"chat_id",
                 CURLFORM_COPYCONTENTS,chat_id.c_str(),
                 CURLFORM_END);
    curl_formadd(start,end,
                 CURLFORM_COPYNAME,"document",
                 CURLFORM_FILE,document.c_str(),
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

void sendDocument::setCaption(const optional<string> &caption) {
    sendDocument::caption = caption;
}


void sendDocument::setDisable_notification(const optional<bool> &disable_notification) {
    sendDocument::disable_notification = disable_notification;
}

void sendDocument::setReply_to_message_id(const optional<int32_t> &reply_to_message_id) {
    sendDocument::reply_to_message_id = reply_to_message_id;
}

/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendDocument::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendDocument::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendDocument::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendDocument::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendDocument::setReplyMarkup(const ForceReply FR){
    sendDocument::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendDocument::getChat_id() const {
    return chat_id;
}

const string &sendDocument::getDocument() const {
    return document;
}

const optional<string> &sendDocument::getCaption() const {
    return caption;
}

const optional<bool> &sendDocument::getDisable_notification() const {
    return disable_notification;
}

const optional<int32_t > &sendDocument::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendDocument::getReply_markup() const {
    return reply_markup;
}
