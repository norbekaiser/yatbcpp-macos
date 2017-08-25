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
#include "types/Location.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Location::Location(float longitude, float latitude) : longitude(longitude), latitude(latitude)
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
Location Location::fromJson(Json::Value Data) {
    if(!Data.isMember("longitude")){
        throw essential_key_missing("Location::longitude is missing");
    }
    if(!Data.isMember("latitude")){
        throw essential_key_missing("Location::latitude is missing");
    }

    float longitude = Data["longitude"].asFloat();
    float latitude = Data["latitude"].asFloat();

    Location ret(longitude,latitude);

    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float Location::getLongitude() const {
    return longitude;
}

float Location::getLatitude() const {
    return latitude;
}
