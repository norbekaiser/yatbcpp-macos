#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/Voice.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Voice::Voice(std::string file_id, int duration):
        file_id(file_id), duration(duration)
{

}

Voice::Voice(const Voice& Voice):
        file_id(Voice.file_id), duration(Voice.duration)
{
    mime_type = Voice.mime_type;
    file_size = Voice.file_size;
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

