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
#include "types/Chat.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chat::Chat(int id, chat_type type) : id(id), type (type)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Chat based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Chat
 */
Chat Chat::fromJson(Json::Value Data) {
    if(!Data.isMember("id")){
        throw essential_key_missing("Chat::id is missing");
    }
    if(!Data.isMember("type")){
        throw essential_key_missing("Chat::type is missing");
    }

    int id = Data["id"].asInt();
    std::string s_chatType = Data["type"].asString();
    chat_type chatType;
    if(s_chatType[0]=='P'){
       chatType = chat_type::Private;
    }
    else if(s_chatType[0]=='G'){
        chatType = chat_type::Group;
    }
    else if(s_chatType[0]=='S'){
        chatType = chat_type::Supergroup;
    }
    else if(s_chatType[0]=='C'){
        chatType = chat_type::Channel;
    }

    Chat ret(id,chatType);
    //additional information//add fast option so additional data is ignored sometimes?
    if(Data.isMember("title")){
        ret.setTitle(Data["title"].asString());
    }
    if(Data.isMember("username")){
        ret.setUsername(Data["username"].asString());
    }
    if(Data.isMember("first_name")){
        ret.setFirst_name(Data["first_name"].asString());
    }
    if(Data.isMember("last_name")){
        ret.setLast_name(Data["last_name"].asString());
    }
    if(Data.isMember("all_members_are_administrators")){
        ret.setAll_members_are_administrators(Data["all_members_are_administrators"].asBool());
    }
    if(Data.isMember("description")){
        ret.setDescription(Data["description"].asString());
    }
    if(Data.isMember("invite_link")){
        ret.setInvite_link(Data["description"].asString());
    }
    return ret;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Chat::setTitle(const optional<string> &title) {
    Chat::title = title;
}

void Chat::setUsername(const optional<string> &username) {
    Chat::username = username;
}

void Chat::setFirst_name(const optional<string> &first_name) {
    Chat::first_name = first_name;
}

void Chat::setLast_name(const optional<string> &last_name) {
    Chat::last_name = last_name;
}

void Chat::setAll_members_are_administrators(const optional<bool> &all_members_are_administrators) {
    Chat::all_members_are_administrators = all_members_are_administrators;
}

void Chat::setDescription(const optional<string> &description) {
    Chat::description = description;
}

void Chat::setInvite_link(const optional<string> &invite_link) {
    Chat::invite_link = invite_link;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Chat::getId() const {
    return id;
}

chat_type Chat::getType() const {
    return type;
}

const optional<string> &Chat::getTitle() const {
    return title;
}

const optional<string> &Chat::getUsername() const {
    return username;
}

const optional<string> &Chat::getFirst_name() const {
    return first_name;
}

const optional<string> &Chat::getLast_name() const {
    return last_name;
}

const optional<bool> &Chat::getAll_members_are_administrators() const {
    return all_members_are_administrators;
}

const optional<string> &Chat::getDescription() const {
    return description;
}

const optional<string> &Chat::getInvite_link() const {
    return invite_link;
}