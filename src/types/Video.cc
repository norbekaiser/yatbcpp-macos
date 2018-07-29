#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/PhotoSize.h"
#include "types/Video.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Video::Video(std::string file_id, int32_t  width, int32_t  height,int32_t  duration):
        file_id(file_id), width(width), height(height), duration(duration)
{

}

Video::Video(const Video& Video):
        file_id(Video.file_id), width(Video.width), height(Video.height), duration(Video.duration)
{
    thumb = Video.thumb;
    mime_type = Video.mime_type;
    file_size = Video.file_size;
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

void Video::setFile_size(const optional<int32_t > &file_size) {
    Video::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Video::getFile_id() const {
    return file_id;
}

int32_t  Video::getWidth() const {
    return width;
}

int32_t  Video::getHeight() const {
    return height;
}

int32_t  Video::getDuration() const {
    return duration;
}

const optional<PhotoSize> &Video::getThumb() const {
    return thumb;
}

const optional<string> &Video::getMime_type() const {
    return mime_type;
}

const optional<int32_t > &Video::getFile_size() const {
    return file_size;
}

