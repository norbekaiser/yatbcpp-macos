#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/PhotoSize.h"
#include "types/Document.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Document::Document(std::string file_id):
        file_id(file_id)
{

}

Document::Document(const Document& Document):
        file_id(Document.file_id)
{
    thumb = Document.thumb;
    file_name = Document.file_name;
    mime_type = Document.mime_type;
    file_size = Document.file_size;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Document::setThumb(const optional<PhotoSize> &thumb) {
    Document::thumb = thumb;
}

void Document::setFile_name(const optional<string> &file_name) {
    Document::file_name = file_name;
}

void Document::setMime_type(const optional<string> &mime_type) {
    Document::mime_type = mime_type;
}

void Document::setFile_size(const optional<int> &file_size) {
    Document::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Document::getFile_id() const {
    return file_id;
}

const optional<PhotoSize> &Document::getThumb() const {
    return thumb;
}

const optional<string> &Document::getFile_name() const {
    return file_name;
}

const optional<string> &Document::getMime_type() const {
    return mime_type;
}

const optional<int> &Document::getFile_size() const {
    return file_size;
}
