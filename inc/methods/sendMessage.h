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

#ifndef YATBCPP_SENDMESSAGE_H
#define YATBCPP_SENDMESSAGE_H

#include "../types/Chat.h"
#include "../types/Message.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardRemove.h"
#include "../types/ForceReply.h"
#include "telegram_methodJSON.h"

namespace yatbcpp{
    class sendMessage : public telegram_methodJSON<Message>{
    public:

        Json::Value toJson();

        sendMessage(std::int64_t  chat_id,std::string text);

        sendMessage(std::string chat_id,std::string text);

        sendMessage(Chat C, std::string text);

        void setParse_mode(const std::optional<std::string> &parse_mode);

        void setDisable_web_page_preview(const std::optional<bool> &disable_web_page_preview);

        void setDisable_notification(const std::optional<bool> &disable_notification);

        void setReply_to_message_id(const std::optional<std::int32_t> &reply_to_message_id);

        void setReplyMarkup(const ReplyKeyboardMarkup RKM);
        void setReplyMarkup(const ReplyKeyboardRemove RKR);
        void setReplyMarkup(const ForceReply FR);

        const std::string &getChat_id() const;

        const std::string &getText() const;

        const std::optional<std::string> &getParse_mode() const;

        const std::optional<bool> &getDisable_web_page_preview() const;

        const std::optional<bool> &getDisable_notification() const;

        const std::optional<std::int32_t> &getReply_to_message_id() const;

        const std::optional<ReplyMarkup> &getReply_markup() const;


    private:
        std::string chat_id;//Maybe simpler because @username or chat_id
        std::string text;
        std::optional<std::string> parse_mode;
        std::optional<bool> disable_web_page_preview;
        std::optional<bool> disable_notification;
        std::optional<std::int32_t> reply_to_message_id;
        std::optional<ReplyMarkup> reply_markup;
    };
}

#endif //YATBCPP_SENDMESSAGE_H
