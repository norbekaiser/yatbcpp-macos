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

#ifndef YATBCPP_USER_H_H
#define YATBCPP_USER_H_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "telegram_type.h"

namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#user
    class User {
    public:

        User(int id,bool is_bot,std::string first_name);

        int getId() const;

        void setLast_name(const std::optional<std::string> &last_name);

        void setUsername(const std::optional<std::string> &username);

        void setLanguage_code(const std::optional<std::string> &language_code);

        const std::string &getFirst_name() const;

        const std::optional<std::string> &getLast_name() const;

        const std::optional<std::string> &getUsername() const;

        const std::optional<std::string> &getLanguage_code() const;

        friend std::ostream& operator<< (std::ostream& o, const User& U);

    private:
        int id;
        bool is_bot;
        std::string first_name;
        std::optional<std::string> last_name;//optional
        std::optional<std::string> username;//optional
        std::optional<std::string> language_code;//optional, sigh c++17 the dream
    };


//    User fromJson(Json::Value Data);

}

#endif //YATBCPP_USER_H_H
