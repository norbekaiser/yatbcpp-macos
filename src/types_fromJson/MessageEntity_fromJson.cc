////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/MessageEntity.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A MessageEntity based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed MessageEntity
     */
    template<> MessageEntity fromJson(Json::Value Data) {
        if (!Data.isMember("type")) {
            throw essential_key_missing("MessageEntity::type is missing");
        }
        if (!Data.isMember("offset")) {
            throw essential_key_missing("MessageEntity::offset is missing");
        }
        if (!Data.isMember("length")) {
            throw essential_key_missing("MessageEntity::length is missing");
        }

        std::string type = Data["type"].asString();
        int offset = Data["offset"].asInt();
        int length = Data["length"].asInt();

        MessageEntity ret(type, offset, length);

        if (Data.isMember("url")) {
            ret.setUrl(Data["url"].asString());
        }
        if (Data.isMember("user")) {
            ret.setUser(yatbcpp::fromJson<User>(Data["user"]));
        }
        return ret;
    }
}