#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/KeyboardButton.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

KeyboardButton::KeyboardButton(std::string text) :
        text(text)
{

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