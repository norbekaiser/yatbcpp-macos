#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/Audio.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Audio::Audio(std::string file_id, int duration):
        file_id(file_id), duration(duration)
{

}

Audio::Audio(const Audio& audio):
        file_id(audio.file_id), duration(audio.duration)
{
    performer = audio.performer;
    title = audio.title;
    mime_type = audio.mime_type;
    file_size = audio.file_size;
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
