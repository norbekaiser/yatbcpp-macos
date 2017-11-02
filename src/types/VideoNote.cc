#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/VideoNote.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VideoNote::VideoNote(std::string file_id, int length, int duration):
        file_id(file_id), length(length), duration(duration)
{

}

VideoNote::VideoNote(const VideoNote& VideoNote):
        file_id(VideoNote.file_id), length(VideoNote.length), duration(VideoNote.duration)
{
    thumb = VideoNote.thumb;
    file_size = VideoNote.file_size;
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
