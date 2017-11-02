
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/InlineQuery.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

InlineQuery::InlineQuery(std::string id, User from, std::string query, std::string offset):
        id(id), from(from), query(query), offset(offset)
{

}

InlineQuery::InlineQuery(const InlineQuery& InlineQuery) :
        id(InlineQuery.id), from(InlineQuery.from), query(InlineQuery.query), offset(InlineQuery.offset)
{
    location = InlineQuery.location;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InlineQuery::setLocation(const optional<Location> &location) {
    InlineQuery::location = location;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &InlineQuery::getId() const {
    return id;
}

const User &InlineQuery::getFrom() const {
    return from;
}

const optional<Location> &InlineQuery::getLocation() const {
    return location;
}

const string &InlineQuery::getQuery() const {
    return query;
}

const string &InlineQuery::getOffset() const {
    return offset;
}


