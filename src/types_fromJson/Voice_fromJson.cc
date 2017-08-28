////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Voice.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A Voice based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Voice
     */
    template<>Voice fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("Voice::file_id is missing");
        }
        if (!Data.isMember("duration")) {
            throw essential_key_missing("Voice::duration is missing");
        }

        std::string file_id = Data["file_id"].asString();
        int duration = Data["duration"].asInt();

        Voice ret(file_id, duration);

        if (Data.isMember("mime_type")) {
            ret.setMime_type(Data["mime_type"].asString());
        }
        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}