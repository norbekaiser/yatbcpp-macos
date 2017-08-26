//
// Created by norbert on 26.08.17.
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
#include "types/KeyboardButton.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

KeyboardButton::KeyboardButton(std::string text) : text(text)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A KeyboardButton based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return KeyboardButton
 */
KeyboardButton KeyboardButton::fromJson(Json::Value Data) {
    if(!Data.isMember("text")){
        throw essential_key_missing("KeyboardButton::text is missing");
    }

    string text = Data["text"].asString();

    KeyboardButton ret(text);

    if(Data.isMember("request_contact")){
        ret.setRequest_contact(Data["request_contact"].asBool());
    }
    if(Data.isMember("request_location")){
        ret.setRequest_location(Data["request_location"].asBool());
    }

    return ret;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KeyboardButton::setRequest_contact(const optional<bool> &request_contact) {
    KeyboardButton::request_contact = request_contact;
}

void KeyboardButton::setRequest_location(const optional<bool> &request_location) {
    KeyboardButton::request_location = request_location;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &KeyboardButton::getText() const {
    return text;
}

const optional<bool> &KeyboardButton::getRequest_contact() const {
    return request_contact;
}

const optional<bool> &KeyboardButton::getRequest_location() const {
    return request_location;
}