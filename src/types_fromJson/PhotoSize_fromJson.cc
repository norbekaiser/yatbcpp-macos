////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/PhotoSize.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A PhotoSize based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed PhotoSize
     */
    template<> PhotoSize fromJson(Json::Value Data) {
        if (!Data.isMember("file_id")) {
            throw essential_key_missing("PhotoSize::file_id is missing");
        }
        if (!Data.isMember("width")) {
            throw essential_key_missing("PhotoSize::width is missing");
        }
        if (!Data.isMember("height")) {
            throw essential_key_missing("PhotoSize::height is missing");
        }

        std::string file_id = Data["file_id"].asString();
        int width = Data["width"].asInt();
        int height = Data["height"].asInt();

        PhotoSize ret(file_id, width, height);

        if (Data.isMember("file_size")) {
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}