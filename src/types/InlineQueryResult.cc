#include "types/InlineQueryResult.h"

using namespace yatbcpp;

InlineQueryResult::InlineQueryResult(std::string type,std::string id):
        type(type), id(id)
{

}

InlineQueryResult::InlineQueryResult(const InlineQueryResult& InlineQueryResult):
        type(InlineQueryResult.type), id(InlineQueryResult.id)
{

}


const std::string &InlineQueryResult::getType() const {
    return type;
}

const std::string &InlineQueryResult::getId() const {
    return id;
}
