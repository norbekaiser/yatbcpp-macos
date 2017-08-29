#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/ReplyKeyboardMarkup.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ReplyKeyboardMarkup::ReplyKeyboardMarkup(std::vector<std::vector<KeyboardButton>> keyboard): keyboard(keyboard)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReplyKeyboardMarkup::setResize_keyboard(const optional<bool> &resize_keyboard) {
    ReplyKeyboardMarkup::resize_keyboard = resize_keyboard;
}

void ReplyKeyboardMarkup::setOne_time_keyboard(const optional<bool> &one_time_keyboard) {
    ReplyKeyboardMarkup::one_time_keyboard = one_time_keyboard;
}

void ReplyKeyboardMarkup::setSelective(const optional<bool> &selective) {
    ReplyKeyboardMarkup::selective = selective;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const vector<vector<KeyboardButton>> &ReplyKeyboardMarkup::getKeyboard() const {
    return keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getResize_keyboard() const {
    return resize_keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getOne_time_keyboard() const {
    return one_time_keyboard;
}

const optional<bool> &ReplyKeyboardMarkup::getSelective() const {
    return selective;
}
