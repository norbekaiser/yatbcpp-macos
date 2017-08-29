////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Venue.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A Location based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Location Voice
     */
    template<> Venue fromJson(Json::Value Data) {
        if (!Data.isMember("location")) {
            throw essential_key_missing("Venue::location is missing");
        }
        if (!Data.isMember("title")) {
            throw essential_key_missing("Venue::title is missing");
        }
        if (!Data.isMember("address")) {
            throw essential_key_missing("Venue::address is missing");
        }

        Location location = fromJson<Location>(Data["location"]);
        string title = Data["title"].asString();
        string address = Data["address"].asString();

        Venue ret(location, title, address);

        if (Data.isMember("foursquare_id")) {
            ret.setFoursquare_id(Data["foursquare_id"].asString());
        }

        return ret;
    }

}