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
// Created by norbert on 12.11.17.
//

#ifndef YATBCPP_SENDDOCUMENT_H
#define YATBCPP_SENDDOCUMENT_H

#include "../types/Chat.h"
#include "../types/Message.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardRemove.h"
#include "../types/ForceReply.h"
#include "telegram_methodJSON.h"
#include "telegram_methodMultipart.h"

namespace yatbcpp{
    class sendDocument : public telegram_methodJSON<Message>, public telegram_methodMultipart<Message>{
    public:


        void add_to_post(struct curl_httppost **start, struct curl_httppost **end);

        Json::Value toJson();

        /**
         *
         * @param chat_id
         * @param document , and Document file id or an Document file location
         * to send local files use methodMultipart
         */
        sendDocument(int chat_id,std::string document);
        /**
         *
         * @param chat_id
         * @param document , and Document file id or an Document file location
         * to send local files use methodMultipart
         */
        sendDocument(std::string chat_id,std::string document);
        /**
         *
         * @param C
         * @param document , and Document file id or an document file location
         * to send local files use methodMultipart, and supply the file direction
         * //TODO improve documentation on send Multipart and SendJson
         */
        sendDocument(Chat C, std::string Document);

        void setCaption(const std::optional<std::string> &caption);

        void setDisable_notification(const std::optional<bool> &disable_notification);

        void setReply_to_message_id(const std::optional<int> &reply_to_message_id);

        void setReplyMarkup(const ReplyKeyboardMarkup RKM);
        void setReplyMarkup(const ReplyKeyboardRemove RKR);
        void setReplyMarkup(const ForceReply FR);

        const std::string &getChat_id() const;

        const std::string &getDocument() const;

        const std::optional<std::string> &getCaption() const;

        const std::optional<bool> &getDisable_notification() const;

        const std::optional<int> &getReply_to_message_id() const;

        const std::optional<ReplyMarkup> &getReply_markup() const;


    private:
        std::string chat_id;
        std::string document;
        std::optional<std::string> caption;
        std::optional<bool> disable_notification;
        std::optional<int> reply_to_message_id;
        std::optional<ReplyMarkup> reply_markup;
    };
}

#endif //YATBCPP_SENDDOCUMENT_H
