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
#ifndef YATBCPP_KEYBOARDBUTTON_H
#define YATBCPP_KEYBOARDBUTTON_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 

namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#keyboardbutton
    class KeyboardButton {
    public:
        KeyboardButton(std::string text);

        void setRequest_contact(const std::optional<bool> &request_contact);

        void setRequest_location(const std::optional<bool> &request_location);

        const std::string &getText() const;

        const std::optional<bool> &getRequest_contact() const;

        const std::optional<bool> &getRequest_location() const;


    private:
        std::string text;
        std::optional<bool> request_contact;
        std::optional<bool> request_location;

    };

}

#endif //YATBCPP_KEYBOARDBUTTON_H
