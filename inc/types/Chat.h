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
#ifndef YATBCPP_CHAT_H
#define YATBCPP_CHAT_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "chat_type.h"

namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#chat */
    class Chat {
    public:
        Chat(int id,chat_type type);

//        static Chat fromJson(Json::Value Data);

        void setTitle(const std::optional<std::string> &title);

        void setUsername(const std::optional<std::string> &username);

        void setFirst_name(const std::optional<std::string> &first_name);

        void setLast_name(const std::optional<std::string> &last_name);

        void setAll_members_are_administrators(const std::optional<bool> &all_members_are_administrators);

        void setDescription(const std::optional<std::string> &description);

        void setInvite_link(const std::optional<std::string> &invite_link);

        int getId() const;

        chat_type getType() const;

        const std::optional<std::string> &getTitle() const;

        const std::optional<std::string> &getUsername() const;

        const std::optional<std::string> &getFirst_name() const;

        const std::optional<std::string> &getLast_name() const;

        const std::optional<bool> &getAll_members_are_administrators() const;

        const std::optional<std::string> &getDescription() const;

        const std::optional<std::string> &getInvite_link() const;


    private:
        int id;
        chat_type type;
        std::optional<std::string> title;//optional
        std::optional<std::string> username;//optional
        std::optional<std::string> first_name;//optional
        std::optional<std::string> last_name;//optional
        std::optional<bool> all_members_are_administrators;//optional
        //Only Returned in getChat
        //ChatPhoto photo

        std::optional<std::string> description;
        std::optional<std::string> invite_link;//Bot invasion incoming?

    };

}


#endif //YATBCPP_CHAT_H
