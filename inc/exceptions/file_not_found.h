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
// Created by norbert on 21.08.17.
//

#ifndef YATBCPP_EXCEPTION_FILE_NOT_FOUND_H
#define YATBCPP_EXCEPTION_FILE_NOT_FOUND_H

#include <ostream>
#include <string>

namespace yatbcpp{
    class file_not_found {
    public:
        file_not_found(std::string message);
        friend std::ostream& operator<< (std::ostream& o, const file_not_found& U);
        friend std::ostream& operator<< (std::ostream& o, const file_not_found* U);
    private:
        std::string message;
    };
}



#endif //YATBCPP_EXCEPTION_FILE_NOT_FOUND_H
