//
// Created by norbert on 23.08.17.
//

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
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
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Location based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Location Voice
 */
Venue Venue::fromJson(Json::Value Data) {
    if(!Data.isMember("location")){
        throw essential_key_missing("Venue::location is missing");
    }
    if(!Data.isMember("title")){
        throw essential_key_missing("Venue::title is missing");
    }
    if(!Data.isMember("address")){
            throw essential_key_missing("Venue::address is missing");
    }

    Location location = Location::fromJson(Data["location"]);
    string title = Data["title"].asString();
    string address = Data["address"].asString();

    Venue ret(location,title,address);

    if(Data.isMember("foursquare_id")){
        ret.setFoursquare_id(Data["foursquare_id"].asString());
    }

    return ret;
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
