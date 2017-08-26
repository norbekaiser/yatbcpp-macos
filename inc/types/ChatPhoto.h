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
// Created by norbert on 25.08.17.
//

#ifndef YATBCPP_CHATPHOTO_H
#define YATBCPP_CHATPHOTO_H

#include <string>
#include <json/json.h>

namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#chatphoto
    class ChatPhoto {
    public:
        ChatPhoto(std::string small_file_id, std::string big_file_id);

        static ChatPhoto fromJson(Json::Value Data);

        const std::string &getSmall_file_id() const;

        const std::string &getBig_file_id() const;

    private:
        std::string small_file_id;
        std::string big_file_id;
    };

}



#endif //YATBCPP_CHATPHOTO_H
