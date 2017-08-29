////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/VideoNote.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A VideoNote based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed VideoNote
     */
    template<> VideoNote fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("VideoNote::file_id is missing");
        }
        if (!Data.isMember("length")) {
            throw essential_key_missing("VideoNote::length is missing");
        }
        if (!Data.isMember("duration")) {
            throw essential_key_missing("VideoNote::duration is missing");
        }

        std::string file_id = Data["file_id"].asString();
        int length = Data["length"].asInt();
        int duration = Data["duration"].asInt();

        VideoNote ret(file_id, length, duration);

        if (Data.isMember("thumb")) {
            ret.setThumb(fromJson<PhotoSize>(Data["thumb"]));
        }
        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}