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
#include "types/Audio.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Audio::Audio(std::string file_id, int duration) : file_id(file_id), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Audio based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Audio
 */
Audio Audio::fromJson(Json::Value Data) {
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Audio::setPerformer(const optional<string> &performer) {
    Audio::performer = performer;
}

void Audio::setTitle(const optional<string> &title) {
    Audio::title = title;
}

void Audio::setMime_type(const optional<string> &mime_type) {
    Audio::mime_type = mime_type;
}

void Audio::setFile_size(const optional<int> &file_size) {
    Audio::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Audio::getFile_id() const {
    return file_id;
}

int Audio::getDuration() const {
    return duration;
}

const optional<string> &Audio::getPerformer() const {
    return performer;
}

const optional<string> &Audio::getTitle() const {
    return title;
}

const optional<string> &Audio::getMime_type() const {
    return mime_type;
}

const optional<int> &Audio::getFile_size() const {
    return file_size;
}
