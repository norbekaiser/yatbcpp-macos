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
// Created by norbert on 27.08.17.
//

#ifndef YATBCPP_SENDAUDIO_H
#define YATBCPP_SENDAUDIO_H

#include "../types/Chat.h"
#include "../types/Message.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardMarkup.h"
#include "../types/ReplyKeyboardRemove.h"
#include "../types/ForceReply.h"
#include "telegram_method.h"

namespace yatbcpp{
    class sendAudio : public telegram_method<Message>{
    public:

        Json::Value toJson();

        sendAudio(int chat_id,std::string audio);

        sendAudio(std::string chat_id,std::string audio);

        sendAudio(Chat C, std::string audio);

        void setCaption(const std::optional<std::string> &caption);

        void setDuration(const std::optional<std::string> &duration);

        void setPerformer(const std::optional<std::string> &performer);

        void setTitle(const std::optional<std::string> &title);

        void setDisable_notification(const std::optional<bool> &disable_notification);

        void setReply_to_message_id(const std::optional<int> &reply_to_message_id);

        void setReplyMarkup(const ReplyKeyboardMarkup RKM);
        void setReplyMarkup(const ReplyKeyboardRemove RKR);
        void setReplyMarkup(const ForceReply FR);

        const std::string &getChat_id() const;

        const std::string &getAudio() const;

        const std::optional<std::string> &getCaption() const;

        const std::optional<std::string> &getDuration() const;

        const std::optional<std::string> &getPerformer() const;

        const std::optional<std::string> &getTitle() const;

        const std::optional<bool> &getDisable_notification() const;

        const std::optional<int> &getReply_to_message_id() const;

        const std::optional<ReplyMarkup> &getReply_markup() const;


    private:
        std::string chat_id;
        std::string audio;//Currently only file id
        std::optional<std::string> caption;
        std::optional<std::string> duration;
        std::optional<std::string> performer;
        std::optional<std::string> title;
        std::optional<bool> disable_notification;
        std::optional<int> reply_to_message_id;
        std::optional<ReplyMarkup> reply_markup;
    };
}

#endif //YATBCPP_SENDAUDIO_H
