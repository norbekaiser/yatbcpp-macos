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
// Created by norbert on 21.08.17.
//

#ifndef YATBCPP_SENDMESSAGE_H
#define YATBCPP_SENDMESSAGE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "Message.h"
#include "Chat.h"


namespace yatbcpp{
    class sendMessage {
    public:
        sendMessage(int chat_id,std::string text);

        sendMessage(std::string chat_id,std::string text);

        sendMessage(Chat C, std::string text);

        void setParse_mode(const std::optional<std::string> &parse_mode);

        void setDisable_web_page_preview(const std::optional<bool> &disable_web_page_preview);

        void setDisable_notification(const std::optional<bool> &disable_notification);

        void setReply_to_message_id(const std::optional<int> &reply_to_message_id);

        void setReply_to_message_id(const Message M);

//        const std::variant<int, std::string> &getChat_id() const;

        const std::string &getChat_id() const;

        const std::string &getText() const;

        const std::optional<std::string> &getParse_mode() const;

        const std::optional<bool> &getDisable_web_page_preview() const;

        const std::optional<bool> &getDisable_notification() const;

        const std::optional<int> &getReply_to_message_id() const;

    private:
        void escape_text_string();
//        std::variant<int,std::string> chat_id;
        std::string chat_id;//Maybe simpler because @username or chat_id
//        std::optional<int> chatid;//will be implemented in the feature some day
        std::string text;
        std::optional<std::string> parse_mode;
        std::optional<bool> disable_web_page_preview;
        std::optional<bool> disable_notification;
        std::optional<int> reply_to_message_id;
//        std::optional<> reply_markup;
    };
}



#endif //YATBCPP_SENDMESSAGE_H
