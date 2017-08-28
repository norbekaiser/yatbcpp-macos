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

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PhotoSize::PhotoSize(std::string file_id, int width, int height) : file_id(file_id), width(width), height(height)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PhotoSize::setFile_size(const optional<int> &file_size) {
    PhotoSize::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &PhotoSize::getFile_id() const {
    return file_id;
}

int PhotoSize::getWidth() const {
    return width;
}

int PhotoSize::getHeight() const {
    return height;
}

const optional<int> &PhotoSize::getFile_size() const {
    return file_size;
}

