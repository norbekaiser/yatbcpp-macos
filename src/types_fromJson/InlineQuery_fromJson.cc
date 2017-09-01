////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/InlineQuery.h"
namespace yatbcpp {

    /**
     * Returns An InlineQuery based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed InlineQuery
     */
    template<>
    InlineQuery fromJson(Json::Value Data) {
        if(!Data.isMember("id")) {
            throw essential_key_missing("Audio::id is missing");
        }
        if(!Data.isMember("from")) {
            throw essential_key_missing("Audio::from is missing");
        }
        if(!Data.isMember("from")) {
            throw essential_key_missing("Audio::from is missing");
        }

        std::string id = Data["id"].asString();
        User from = fromJson<User>(Data["from"]);
        std::string query = Data["query"].asString();
        std::string offset = Data["offset"].asString();

        InlineQuery ret(id, from, query,offset);

        if(Data.isMember("location")){
            ret.setLocation(fromJson<Location>(Data["location"]));
        }


        return ret;
   }
}
