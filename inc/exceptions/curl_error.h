//    Copyright (c) 2017,2018 Norbert Rühl
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
// Created by norbert on 22.08.17.
//

#ifndef YATBCPP_CURL_API_ERROR_H
#define YATBCPP_CURL_API_ERROR_H

#include <ostream>
#include <string>

namespace yatbcpp{
    class curl_error {
    public:
        curl_error(int errorcode, std::string message);
        friend std::ostream& operator<< (std::ostream& o, const curl_error& U);
        friend std::ostream& operator<< (std::ostream& o, const curl_error* U);
    private:
        int errorcode;
        std::string message;
    };
}

#endif //YATBCPP_TELEGRAM_API_ERROR_H
