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
#include "types/telegram_type.h"
#include "types/PhotoSize.h"
#include "types/Video.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Video::Video(std::string file_id, int width, int height,int duration) : file_id(file_id), width(width), height(height), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Video::setThumb(const optional<PhotoSize> &thumb) {
    Video::thumb = thumb;
}

void Video::setMime_type(const optional<string> &mime_type) {
    Video::mime_type = mime_type;
}

void Video::setFile_size(const optional<int> &file_size) {
    Video::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Video::getFile_id() const {
    return file_id;
}

int Video::getWidth() const {
    return width;
}

int Video::getHeight() const {
    return height;
}

int Video::getDuration() const {
    return duration;
}

const optional<PhotoSize> &Video::getThumb() const {
    return thumb;
}

const optional<string> &Video::getMime_type() const {
    return mime_type;
}

const optional<int> &Video::getFile_size() const {
    return file_size;
}

