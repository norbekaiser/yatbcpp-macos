//
// Created by norbert on 18.08.17.
//

#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/Message.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message::Message(int message_id, int date, Chat chat) : message_id(message_id), date(date), chat(chat)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Message based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Message
 */
Message Message::fromJson(Json::Value Data) {
    if(!Data.isMember("message_id")){
        //message_id is missing
        throw essential_key_missing("Message::message_id is missing");
    }
    if(!Data.isMember("date")){
        throw essential_key_missing("Message::date is missing");
    }
    if(!Data.isMember("chat")){
        throw essential_key_missing("Message::chat is missing");
    }

    int message_id = Data["message_id"].asInt();
    int date = Data["date"].asInt();
    Chat chat = Chat::fromJson(Data["chat"]);

    Message ret(message_id,date,chat);
    //Additional Data parsing
    if(Data.isMember("from")){
        User U= User::fromJson(Data["from"]);
        ret.setFrom(U);
    }
    if(Data.isMember("forward_from")){
        User U= User::fromJson(Data["forward_from"]);
        ret.setForward_from(U);
    }
    if(Data.isMember("forward_from_chat")){
        Chat C= Chat::fromJson(Data["forward_from_chat"]);
        ret.setForward_from_chat(C);
    }
    if(Data.isMember("forward_from_message_id")){
        ret.setForward_from_message_id(Data["forward_from_message_id"].asInt());
    }
    if(Data.isMember("forward_date")){
        ret.setForward_date(Data["forward_date"].asInt());
    }
    //todo reply to message
    if(Data.isMember("edit_date")){
        ret.setEdit_date(Data["edit_date"].asInt());
    }
    if(Data.isMember("text")){
        ret.setText(Data["text"].asString());
    }
    if(Data.isMember("entities")) {
        for (int i = 0; i < Data["entities"].size(); i++) {
            Json::Value small_entity;
            small_entity = Data["entities"][i];
            MessageEntity messageEntity = MessageEntity::fromJson(small_entity);
            ret.addEntity(messageEntity);
        }
    }

    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Message::setFrom(const optional<User> &from) {
    Message::from = from;
}

void Message::setForward_from(const optional<User> &forward_from) {
    Message::forward_from = forward_from;
}

void Message::setForward_from_chat(const optional<Chat> &forward_from_chat) {
    Message::forward_from_chat = forward_from_chat;
}

void Message::setForward_from_message_id(const optional<int> &forward_from_message_id) {
    Message::forward_from_message_id = forward_from_message_id;
}

void Message::setForward_date(const optional<int> &forward_date) {
    Message::forward_date = forward_date;
}

//void Message::setReply_to_message(const optional<Message *> &reply_to_message) {
//    Message::reply_to_message = reply_to_message;
//}

void Message::setEdit_date(const optional<int> &edit_date) {
    Message::edit_date = edit_date;
}

void Message::setText(const optional<string> &text) {
    Message::text = text;
}

void Message::addEntity(const MessageEntity &messageEntity){
    entities.push_back(messageEntity);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Message::getMessage_id() const {
    return message_id;
}

const optional<User> &Message::getFrom() const {
    return from;
}

int Message::getDate() const {
    return date;
}

const Chat &Message::getChat() const {
    return chat;
}

const optional<User> &Message::getForward_from() const {
    return forward_from;
}

const optional<Chat> &Message::getForward_from_chat() const {
    return forward_from_chat;
}

const optional<int> &Message::getForward_from_message_id() const {
    return forward_from_message_id;
}

const optional<int> &Message::getForward_date() const {
    return forward_date;
}

//const optional<Message *> &Message::getReply_to_message() const {
//    return reply_to_message;
//}

const optional<int> &Message::getEdit_date() const {
    return edit_date;
}

const optional<string> &Message::getText() const {
    return text;
}

const vector<MessageEntity> &Message::getEntities() const {
    return entities;
}



