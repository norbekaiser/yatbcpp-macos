////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Chat.h"

namespace yatbcpp{

    /**
    * Returns A Chat based on a Json Object
    * @param Data   a Json Object Containing the necessary and Optional Fields
    * @return Parsed Chat
    */
    template <> Chat fromJson(Json::Value Data) {
        if(!Data.isMember("id")){
            throw essential_key_missing("Chat::id is missing");
        }
        if(!Data.isMember("type")){
            throw essential_key_missing("Chat::type is missing");
        }

        std::int64_t id = Data["id"].asInt64();
        std::string s_chatType = Data["type"].asString();
        chat_type chatType = yatbcpp::fromString<chat_type>(Data["type"].asString());
        
        /*if(s_chatType[0]=='P'){
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
        }*/

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
}