////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Location.h"

namespace yatbcpp {
    /**
     * Returns A Location based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Location Voice
     */
    template<> Location fromJson(Json::Value Data) {
        if (!Data.isMember("longitude")) {
            throw essential_key_missing("Location::longitude is missing");
        }
        if (!Data.isMember("latitude")) {
            throw essential_key_missing("Location::latitude is missing");
        }

        float longitude = Data["longitude"].asFloat();
        float latitude = Data["latitude"].asFloat();

        Location ret(longitude, latitude);

        return ret;
    }
}