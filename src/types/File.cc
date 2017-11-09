#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/File.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

File::File(std::string file_id):
        file_id(file_id)
{

}

File::File(const File& File):
        file_id(File.getFile_id())
{
    file_size = File.file_size;
    file_path = File.file_path;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void File::setFile_size(const optional<int> &file_size) {
    File::file_size = file_size;
}

void File::setFile_path(const optional<string> &file_path) {
    File::file_path = file_path;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &File::getFile_id() const {
    return file_id;
}

const optional<int> &File::getFile_size() const {
    return file_size;
}

const optional<string> &File::getFile_path() const {
    return file_path;
}

