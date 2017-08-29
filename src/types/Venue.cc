#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/Venue.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Venue::Venue(Location location, std::string title, std::string address) : location(location), title(title), address(address)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Venue::setFoursquare_id(const optional<string> &foursquare_id) {
    Venue::foursquare_id = foursquare_id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Location &Venue::getLocation() const {
    return location;
}

const string &Venue::getTitle() const {
    return title;
}

const string &Venue::getAddress() const {
    return address;
}

const optional<string> &Venue::getFoursquare_id() const {
    return foursquare_id;
}
