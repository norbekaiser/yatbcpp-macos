////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/File.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A File based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return File Voice
     */
    template<> File fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("File::file_id is missing");
        }

        string file_id = Data["address"].asString();

        File ret(file_id);

        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        if (Data.isMember("file_path")) {
            ret.setFile_path(Data["file_path"].asString());
        }

        return ret;
    }
}
