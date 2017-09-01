#include <string>
#include <json/json.h>
#include "methods/telegram_methodJSON.h"
#include "methods/forwardMessage.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

forwardMessage::forwardMessage(Chat chat_id, Message from) :
        telegram_methodJSON("forwardMessage"),
        chat_id(to_string(chat_id.getId())), from_chat_id(to_string(from.getChat().getId())), message_id(from.getMessage_id())
{

}

forwardMessage::forwardMessage(std::string chat_id, std::string from_chat_id, int message_id) :
        telegram_methodJSON("forwardMessage"),
        chat_id(chat_id), from_chat_id(from_chat_id), message_id(message_id)
{

}

forwardMessage::forwardMessage(int chat_id, int from_chat_id, int message_id) :
        telegram_methodJSON("forwardMessage"),
        chat_id(to_string(chat_id)), from_chat_id(to_string(from_chat_id)), message_id(message_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Json::Value forwardMessage::toJson(){
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["from_chat_id"] = getFrom_chat_id();
    Outgoing["message_id"] = getMessage_id();
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    return Outgoing;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void forwardMessage::setDisable_notification(const optional<bool> &disable_notification) {
    forwardMessage::disable_notification = disable_notification;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &forwardMessage::getChat_id() const {
    return chat_id;
}

const string &forwardMessage::getFrom_chat_id() const {
    return from_chat_id;
}

const optional<bool> &forwardMessage::getDisable_notification() const {
    return disable_notification;
}

int forwardMessage::getMessage_id() const {
    return message_id;
}
