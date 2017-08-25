//
// Created by norbert on 23.08.17.
//

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/Voice.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Voice::Voice(std::string file_id, int duration) : file_id(file_id), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Voice based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Voice
 */
Voice Voice::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("Voice::file_id is missing");
    }
    if(!Data.isMember("duration")){
        throw essential_key_missing("Voice::duration is missing");
    }

    std::string file_id = Data["file_id"].asString();
    int duration = Data["duration"].asInt();

    Voice ret(file_id,duration);

    if(Data.isMember("mime_type")){
        ret.setMime_type(Data["mime_type"].asString());
    }
    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Voice::setMime_type(const optional<string> &mime_type) {
    Voice::mime_type = mime_type;
}

void Voice::setFile_size(const optional<int> &file_size) {
    Voice::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Voice::getFile_id() const {
    return file_id;
}

int Voice::getDuration() const {
    return duration;
}

const optional<string> &Voice::getMime_type() const {
    return mime_type;
}

const optional<int> &Voice::getFile_size() const {
    return file_size;
}

