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
// Created by norbert on 01.09.17.
//

#ifndef YATBCPP_INLINEQUERYRESULT_H
#define YATBCPP_INLINEQUERYRESULT_H

#include <string>
#include <json/json.h>
#include <iostream>
namespace yatbcpp{

    class InlineQueryResult {
        
    public:
        InlineQueryResult(std::string type,std::string id);
        
        InlineQueryResult(const InlineQueryResult& InlineQueryResult);
        
        virtual Json::Value toJson(){
            Json::Value ret;
            return ret;
        }
        
    protected:
        std::string type;
        
        std::string id;
        
    public:
        const std::string &getType() const;
    
        const std::string &getId() const;
    };
}

#endif //YATBCPP_INLINEQUERYRESULT_H
