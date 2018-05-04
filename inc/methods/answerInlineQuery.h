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
#ifndef YATBCPP_ANSWERINLINEQUERY_H
#define YATBCPP_ANSWERINLINEQUERY_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <memory>
#include "telegram_simplemethodJSON.h"
#include "../types/InlineQueryResult.h"


namespace yatbcpp{
    class answerInlineQuery : public telegram_simplemethodJSON{
    public:
        answerInlineQuery(std::string inline_query_id,std::vector<std::shared_ptr<InlineQueryResult>> results);
        answerInlineQuery(std::string inline_query_id);
        Json::Value toJson();

        void addInlineQueryResult(std::shared_ptr<InlineQueryResult> IQR);

        void setCache_time(const std::optional<int> &cache_time);

        void setIs_personal(const std::optional<bool> &is_personal);

        void setNext_offset(const std::optional<std::string> &next_offset);

        void setSwitch_pm_text(const std::optional<std::string> &switch_pm_text);

        void setSwitch_pm_parameter(const std::optional<std::string> &switch_pm_parameter);

        const std::string &getInline_query_id() const;

        const std::optional<int> &getCache_time() const;

        const std::optional<bool> &getIs_personal() const;

        const std::optional<std::string> &getNext_offset() const;

        const std::optional<std::string> &getSwitch_pm_text() const;

        const std::optional<std::string> &getSwitch_pm_parameter() const;

    private:
        std::string inline_query_id;
        std::vector<std::shared_ptr<InlineQueryResult>> results;
        std::optional<int> cache_time;
        std::optional<bool> is_personal;
        std::optional<std::string> next_offset;
        std::optional<std::string> switch_pm_text;
        std::optional<std::string> switch_pm_parameter;
    };
}



#endif //YATBCPP_ANSWERINLINEQUERY_H
