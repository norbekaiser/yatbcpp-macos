////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Audio.h"
namespace yatbcpp{

    /**
     * Returns A Audio based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Audio
     */
    template <> Audio fromJson(Json::Value Data) {
        if(!Data.isMember("file_id")){
            throw essential_key_missing("Audio::file_id is missing");
        }
        if(!Data.isMember("duration")){
            throw essential_key_missing("Audio::duration is missing");
        }

        std::string file_id = Data["file_id"].asString();
        int duration = Data["duration"].asInt();

        Audio ret(file_id,duration);

        if(Data.isMember("performer")){
            ret.setPerformer(Data["performer"].asString());
        }
        if(Data.isMember("title")){
            ret.setTitle(Data["title"].asString());
        }
        if(Data.isMember("mime_type")){
            ret.setMime_type(Data["mime_type"].asString());
        }
        if(Data.isMember("file_size")){
            ret.setFile_size(Data["file_size"].asInt());
        }
        return ret;
    }
}