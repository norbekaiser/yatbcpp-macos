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

#ifndef YATBCPP_INLINEQUERY_H
#define YATBCPP_INLINEQUERY_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "User.h"
#include "Location.h"

namespace yatbcpp{
    class InlineQuery {
    public:

        InlineQuery(std::string id, User from, std::string query, std::string offset);
        
        InlineQuery(const InlineQuery& InlineQuery);

        void setLocation(const std::optional<Location> &location);

        const std::string &getId() const;

        const User &getFrom() const;

        const std::optional<Location> &getLocation() const;

        const std::string &getQuery() const;

        const std::string &getOffset() const;

    private:
        std::string id;
        User from;
        std::optional<Location> location;
        std::string query;
        std::string offset;
    };

}


#endif //YATBCPP_INLINEQUERY_H
