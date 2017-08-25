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
#include "types/File.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

File::File(std::string file_id) : file_id(file_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A File based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return File Voice
 */
File File::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("File::file_id is missing");
    }

    string file_id = Data["address"].asString();

    File ret(file_id);

    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    if(Data.isMember("file_path")){
        ret.setFile_path(Data["file_path"].asString());
    }

    return ret;
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

