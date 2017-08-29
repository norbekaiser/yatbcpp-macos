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

#ifndef YATBCPP_UPDATE_H
#define YATBCPP_UPDATE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "Message.h"

namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#update */
    class Update {
    public:
        Update(int update_id);

        void setMessage(const std::optional<Message> &message);

        void setEdited_message(const std::optional<Message> &edited_message);

        void setChannel_post(const std::optional<Message> &channel_post);

        void setEdited_channel_post(const std::optional<Message> &edited_channel_post);

        int getUpdate_id() const;

        const std::optional<Message> &getMessage() const;

        const std::optional<Message> &getEdited_message() const;

        const std::optional<Message> &getChannel_post() const;

        const std::optional<Message> &getEdited_channel_post() const;

    private:
        int update_id;
        std::optional<Message> message;
        std::optional<Message> edited_message;
        std::optional<Message> channel_post;
        std::optional<Message> edited_channel_post;
//        InlineQuery inline_query;//optional
//        ChosenInlineResul chosen_inline_resultt;//optional
//        CallbackQuery callback_query;//optional
//        ShippingQuery shipping_query;//optional
//        PreCheckoutQuery pre_checkout_query;//optional

    };

}



#endif //YATBCPP_UPDATE_H
