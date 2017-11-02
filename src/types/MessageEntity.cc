//
// Created by norbert on 23.08.17.
//

#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "exceptions/essential_key_missing.h"
#include "types/MessageEntity.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MessageEntity::MessageEntity(std::string type, int offset, int length):
        type(type), offset(offset), length(length)
{

    if(type.compare("mention")){}
    else if(type.compare("hashtag")){}
    else if(type.compare("bot_command")){}
    else if(type.compare("url")){}
    else if(type.compare("email")){}
    else if(type.compare("bold")){}
    else if(type.compare("italic")){}
    else if(type.compare("code")){}
    else if(type.compare("pre")){}
    else if(type.compare("text_link")){}
    else if(type.compare("text_mention")){}
    else{
        throw essential_key_missing("MessageEntity::type <"+type+"> is not a type which was wished for");//TODO enum
    }


}

MessageEntity::MessageEntity(const MessageEntity& MessageEntity):
    type(MessageEntity.type), offset(MessageEntity.offset), length(MessageEntity.length)
{
    url = MessageEntity.url;
    user = MessageEntity.user;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MessageEntity::setUrl(const optional<string> &url) {
    if(type.compare("text_link")){
        MessageEntity::url = url;
    }
    else{
        throw essential_key_missing("For setting MessageEntity::url in MessageEntity::type::"+type+" is missing text_link");
    }

}

void MessageEntity::setUser(const optional<User> &user) {
    if(type.compare("text_mention”")){
        MessageEntity::user= user;
    }
    else{
        throw essential_key_missing("For setting MessageEntity::user in MessageEntity::type::"+type+" is missing text_mention");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &MessageEntity::getType() const {
    return type;
}

int MessageEntity::getOffset() const {
    return offset;
}

int MessageEntity::getLength() const {
    return length;
}

const optional<string> &MessageEntity::getUrl() const {
    return url;
}

const optional<User> &MessageEntity::getUser() const {
    return user;
}
