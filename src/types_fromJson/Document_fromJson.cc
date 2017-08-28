////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Document.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A Document based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Document
     */
    template<> Document fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("Document::file_id is missing");
        }

        std::string file_id = Data["file_id"].asString();

        Document ret(file_id);

        if (Data.isMember("thumb")) {
            ret.setThumb(fromJson<PhotoSize>(Data["thumb"]));
        }
        if (Data.isMember("file_name")) {
            ret.setFile_name(Data["file_name"].asString());
        }
        if (Data.isMember("mime_type")) {
            ret.setMime_type(Data["mime_type"].asString());
        }
        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}