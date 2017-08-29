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
// Created by norbert on 23.08.17.
//

#ifndef YATBCPP_VOICE_H
#define YATBCPP_VOICE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 

namespace yatbcpp{
    //See also https://core.telegram.org/bots/api#voice
    class Voice {
    public:
        Voice(std::string file_id, int duration);

//        static Voice fromJson(Json::Value Data);

        void setMime_type(const std::optional<std::string> &mime_type);

        void setFile_size(const std::optional<int> &file_size);

        const std::string &getFile_id() const;

        int getDuration() const;

        const std::optional<std::string> &getMime_type() const;

        const std::optional<int> &getFile_size() const;


    private:
        std::string file_id;
        int duration;
        std::optional<std::string> mime_type;
        std::optional<int> file_size;

    };

}

#endif //YATBCPP_VOICE_H
