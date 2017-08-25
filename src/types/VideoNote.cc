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
#include "types/VideoNote.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VideoNote::VideoNote(std::string file_id, int length, int duration) : file_id(file_id), length(length), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A VideoNote based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed VideoNote
 */
VideoNote VideoNote::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("VideoNote::file_id is missing");
    }
    if(!Data.isMember("length")){
        throw essential_key_missing("VideoNote::length is missing");
    }
    if(!Data.isMember("duration")){
        throw essential_key_missing("VideoNote::duration is missing");
    }

    std::string file_id = Data["file_id"].asString();
    int length = Data["length"].asInt();
    int duration = Data["duration"].asInt();

    VideoNote ret(file_id,length,duration);

    if(Data.isMember("thumb")){
        ret.setThumb(PhotoSize::fromJson(Data["thumb"]));
    }
    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VideoNote::setThumb(const optional<PhotoSize> &thumb) {
    VideoNote::thumb = thumb;
}

void VideoNote::setFile_size(const optional<int> &file_size) {
    VideoNote::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &VideoNote::getFile_id() const {
    return file_id;
}

int VideoNote::getLength() const {
    return length;
}

int VideoNote::getDuration() const {
    return duration;
}

const optional<PhotoSize> &VideoNote::getThumb() const {
    return thumb;
}

const optional<int> &VideoNote::getFile_size() const {
    return file_size;
}
