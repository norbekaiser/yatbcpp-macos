////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/User.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A User based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed User
     */
    template<> User fromJson<User>(Json::Value Data) {
//User fromJson(Json::Value Data) {
        //Checking for essential fields, method somehow? check <"first_name">
        if (!Data.isMember("id")) {
            throw essential_key_missing("User::id is missing");
        }
        if (!Data.isMember("is_bot")) {
            throw essential_key_missing("User::is_bot is missing");
        }
        if (!Data.isMember("first_name")) {
            throw essential_key_missing("User::first_name is missing");
        }
        //Extracting the essential information
        std::int32_t id = Data["id"].asInt();
        bool is_bot = Data["is_bot"].asBool();
        std::string first_name = Data["first_name"].asString();
        //Creating the for return created object
        User ret(id, is_bot, first_name);
        //Adding Optional/Additional Information
        if (Data.isMember("last_name")) {
            ret.setLast_name(Data["last_name"].asString());
        }
        if (Data.isMember("username")) {
            ret.setUsername(Data["username"].asString());
        }
        if (Data.isMember("language_code")) {
            ret.setLanguage_code(Data["language_code"].asString());
        }
        return ret;
    }
}