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
// Created by norbert on 26.08.17.
//

#ifndef YATBCPP_REPLYKEYBOARDMARKUP_H
#define YATBCPP_REPLYKEYBOARDMARKUP_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <vector>
#include "KeyboardButton.h"
#include "ReplyMarkup.h"


namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#replykeyboardmarkup
    class ReplyKeyboardMarkup : public ReplyMarkup{
    public:
        ReplyKeyboardMarkup(std::vector<std::vector<KeyboardButton>> keyboard);

        void setResize_keyboard(const std::optional<bool> &resize_keyboard);

        void setOne_time_keyboard(const std::optional<bool> &one_time_keyboard);

        void setSelective(const std::optional<bool> &selective);

        const std::vector<std::vector<KeyboardButton>> &getKeyboard() const;

        const std::optional<bool> &getResize_keyboard() const;

        const std::optional<bool> &getOne_time_keyboard() const;

        const std::optional<bool> &getSelective() const;


    private:
        std::vector<std::vector<KeyboardButton>> keyboard;
        std::optional<bool> resize_keyboard;
        std::optional<bool> one_time_keyboard;
        std::optional<bool> selective;

    };

}

#endif //YATBCPP_REPLYKEYBOARDMARKUP_H
