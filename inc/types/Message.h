//    Copyright (c) 2017 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.
//
// Created by norbert on 18.08.17.
//

#ifndef YATBCPP_MESSAGE_H
#define YATBCPP_MESSAGE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "User.h"
#include "Chat.h"
#include "MessageEntity.h"


namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#message
    class Message{
    public:
        Message(int message_id,int date,Chat chat);

        static Message fromJson(Json::Value Data);

        void setFrom(const std::optional<User> &from);

        void setForward_from(const std::optional<User> &forward_from);

        void setForward_from_chat(const std::optional<Chat> &forward_from_chat);

        void setForward_from_message_id(const std::optional<int> &forward_from_message_id);

        void setForward_date(const std::optional<int> &forward_date);

//        void setReply_to_message(const std::optional<Message *> &reply_to_message);

        void setEdit_date(const std::optional<int> &edit_date);

        void setText(const std::optional<std::string> &text);

        void addEntity(const MessageEntity &messageEntity);

        int getMessage_id() const;

        const std::optional<User> &getFrom() const;

        int getDate() const;

        const Chat &getChat() const;

        const std::optional<User> &getForward_from() const;

        const std::optional<Chat> &getForward_from_chat() const;

        const std::optional<int> &getForward_from_message_id() const;

        const std::optional<int> &getForward_date() const;

//        const std::optional<Message *> &getReply_to_message() const;//auto generated came in here, todo later

        const std::optional<int> &getEdit_date() const;

        const std::optional<std::string> &getText() const;

        const std::vector<MessageEntity> &getEntities() const;

    private:

        int message_id;
        std::optional<User> from;//Optional
        int date;
        Chat chat;
        std::optional<User> forward_from;
        std::optional<Chat> forward_from_chat;
        std::optional<int> forward_from_message_id;
        std::optional<int> forward_date;
//        std::optional<Message*> reply_to_message;//=NULL;//Optional//sigh auch das noch//naja dann als pointer, ggf adden?
        std::optional<int> edit_date;
        std::optional<std::string> text;

        std::vector<MessageEntity> entities;

    };

}

#endif //YATBCPP_MESSAGE_H
