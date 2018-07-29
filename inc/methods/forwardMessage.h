//    Copyright (c) 2017,2018 Norbert Rühl
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
// Created by norbert on 27.08.17.
//

#ifndef YATBCPP_FORWARDMESSAGE_H
#define YATBCPP_FORWARDMESSAGE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "telegram_methodJSON.h"
#include "../types/Message.h"
#include "../types/Chat.h"

namespace yatbcpp{
    class forwardMessage : public telegram_methodJSON<Message>{
    public:
        forwardMessage(std::string chat_id, std::string from_chat_id, std::int32_t message_id);
        forwardMessage(std::int64_t chat_id, std::int64_t from_chat_id, std::int32_t message_id);
        forwardMessage(Chat chat_id, Message from);
        Json::Value toJson();

        const std::string &getChat_id() const;

        const std::string &getFrom_chat_id() const;

        const std::optional<bool> &getDisable_notification() const;

        std::int32_t getMessage_id() const;

        void setDisable_notification(const std::optional<bool> &disable_notification);

    private:
        std::string chat_id;
        std::string from_chat_id;
        std::optional<bool> disable_notification;
        std::int32_t message_id;
    };
}



#endif //YATBCPP_FORWARDMESSAGE_H
