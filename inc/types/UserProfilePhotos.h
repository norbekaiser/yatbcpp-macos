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
// Created by norbert on 24.08.17.
//

#ifndef YATBCPP_USERPROFILEPHOTOS_H
#define YATBCPP_USERPROFILEPHOTOS_H

#include <vector>
#include "PhotoSize.h"

namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#userprofilephotos */
    class UserProfilePhotos {
    public:
        UserProfilePhotos(int total_count,std::vector<std::vector<PhotoSize>> photos);
        
        UserProfilePhotos(const UserProfilePhotos& UserProfilePhotos);

        int getTotal_count() const;

        const std::vector<std::vector<PhotoSize>> &getPhotos() const;

    private:
        int total_count;
        std::vector<std::vector<PhotoSize> > photos;


    };

}

#endif //YATBCPP_USERPROFILEPHOTOS_H
