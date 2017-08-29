////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/ChatPhoto.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A ChatPhoto based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed ChatPhoto
     */
    template<> ChatPhoto fromJson(Json::Value Data) {
        if (!Data.isMember("small_file_id")) {
            throw essential_key_missing("ChatPhoto::small_file_id is missing");
        }
        if (!Data.isMember("big_file_id")) {
            throw essential_key_missing("ChatPhoto::big_file_id is missing");
        }

        std::string small_file_id = Data["file_id"].asString();
        std::string big_file_id = Data["file_id"].asString();

        ChatPhoto ret(small_file_id, big_file_id);

        return ret;
    }
}