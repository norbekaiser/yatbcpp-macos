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
#ifndef YATBCPP_FILE_H
#define YATBCPP_FILE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 

namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#file */
    class File {
    public:
        File(std::string file_id);

        void setFile_size(const std::optional<int> &file_size);

        void setFile_path(const std::optional<std::string> &file_path);

        const std::string &getFile_id() const;

        const std::optional<int> &getFile_size() const;

        const std::optional<std::string> &getFile_path() const;

    private:
        std::string file_id;
        std::optional<int> file_size;
        std::optional<std::string> file_path;

    };

}

#endif //YATBCPP_FILE_H
