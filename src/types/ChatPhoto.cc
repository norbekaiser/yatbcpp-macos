//
// Created by norbert on 25.08.17.
//
#include <string>
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/ChatPhoto.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ChatPhoto::ChatPhoto(std::string small_file_id, std::string big_file_id) : small_file_id(small_file_id), big_file_id(big_file_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A ChatPhoto based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed ChatPhoto
 */
ChatPhoto ChatPhoto::fromJson(Json::Value Data) {
    if(!Data.isMember("small_file_id")){
        throw essential_key_missing("ChatPhoto::small_file_id is missing");
    }
    if(!Data.isMember("big_file_id")){
        throw essential_key_missing("ChatPhoto::big_file_id is missing");
    }

    std::string small_file_id = Data["file_id"].asString();
    std::string big_file_id = Data["file_id"].asString();

    ChatPhoto ret(small_file_id,big_file_id);

    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &ChatPhoto::getSmall_file_id() const {
    return small_file_id;
}

const string &ChatPhoto::getBig_file_id() const {
    return big_file_id;
}
