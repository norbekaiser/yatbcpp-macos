////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Contact.h"

using namespace std;

namespace yatbcpp {

    /**
     * Returns A Contact based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Contact
     */
    template<> Contact fromJson(Json::Value Data) {
        if (!Data.isMember("phone_number")) {
            throw essential_key_missing("Contact::file_id is missing");
        }
        if (!Data.isMember("first_name")) {
            throw essential_key_missing("Contact::duration is missing");
        }
        std::string phone_number = Data["phone_number"].asString();
        std::string first_name = Data["first_name"].asString();

        Contact ret(phone_number, first_name);

        if (Data.isMember("last_name")) {
            ret.setLast_name(Data["last_name"].asString());
        }
        if (Data.isMember("user_id")) {
            ret.setUser_id(Data["user_id"].asInt());
        }
        return ret;
    }

}
