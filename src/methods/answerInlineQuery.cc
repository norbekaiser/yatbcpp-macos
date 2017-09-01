#include <json/json.h>
#include <iostream>
#include "methods/answerInlineQuery.h"

using namespace yatbcpp;
using namespace std;

answerInlineQuery::answerInlineQuery(std::string inline_query_id,std::vector<InlineQueryResult> results) :
        telegram_simplemethodJSON("answerInlineQuery"),
        inline_query_id(inline_query_id), results(results)
{

}

Json::Value answerInlineQuery::toJson(){
    Json::Value Outgoing;
    Outgoing["inline_query_id"] = getInline_query_id();
    for(int i=0;i<results.size();i++){
        std::cout << "DEBUG:: RESULT" << std::endl;
//        InlineQueryResult* iqr = &(results[i]);
//        cerr << iqr->getType() << endl;
        Outgoing["result"][i] = results[i].toJson();
//        Outgoing["result"][i] = iqr->toJson();
    }
    if(cache_time){
        Outgoing["cache_time"] = cache_time.value();
    }
    if(is_personal){
        Outgoing["is_personal"] = is_personal.value();
    }
    if(next_offset){
        Outgoing["next_offset"] = next_offset.value();
    }
    if(switch_pm_text){
            Outgoing["switch_pm_text"] = switch_pm_text.value();
    }
    if(switch_pm_parameter){
            Outgoing["switch_pm_parameter"] = switch_pm_parameter.value();
    }


    return Outgoing;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void answerInlineQuery::setCache_time(const optional<int> &cache_time) {
    answerInlineQuery::cache_time = cache_time;
}

void answerInlineQuery::setIs_personal(const optional<bool> &is_personal) {
    answerInlineQuery::is_personal = is_personal;
}

void answerInlineQuery::setNext_offset(const optional<string> &next_offset) {
    answerInlineQuery::next_offset = next_offset;
}

void answerInlineQuery::setSwitch_pm_text(const optional<string> &switch_pm_text) {
    answerInlineQuery::switch_pm_text = switch_pm_text;
}

void answerInlineQuery::setSwitch_pm_parameter(const optional<string> &switch_pm_parameter) {
    answerInlineQuery::switch_pm_parameter = switch_pm_parameter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &answerInlineQuery::getInline_query_id() const {
    return inline_query_id;
}

const vector<InlineQueryResult> &answerInlineQuery::getResults() const {
    return results;
}

const optional<int> &answerInlineQuery::getCache_time() const {
    return cache_time;
}

const optional<bool> &answerInlineQuery::getIs_personal() const {
    return is_personal;
}

const optional<string> &answerInlineQuery::getNext_offset() const {
    return next_offset;
}

const optional<string> &answerInlineQuery::getSwitch_pm_text() const {
    return switch_pm_text;
}

const optional<string> &answerInlineQuery::getSwitch_pm_parameter() const {
    return switch_pm_parameter;
}

