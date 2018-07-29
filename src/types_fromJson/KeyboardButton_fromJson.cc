////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/KeyboardButton.h"

using namespace std;

namespace yatbcpp {

    /**
     * Returns A KeyboardButton based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return KeyboardButton
     */
    template<> KeyboardButton fromJson(Json::Value Data) {
        if (!Data.isMember("text")) {
            throw essential_key_missing("KeyboardButton::text is missing");
        }

        std::string text = Data["text"].asString();

        KeyboardButton ret(text);

        if (Data.isMember("request_contact")) {
            ret.setRequest_contact(Data["request_contact"].asBool());
        }
        if (Data.isMember("request_location")) {
            ret.setRequest_location(Data["request_location"].asBool());
        }

        return ret;
    }

}