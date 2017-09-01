#include "types/InlineQueryResult.h"

InlineQueryResult::InlineQueryResult(std::string type,std::string id):
        type(type), id(id)
{

}

const std::string &InlineQueryResult::getType() const {
    return type;
}

const std::string &InlineQueryResult::getId() const {
    return id;
}
