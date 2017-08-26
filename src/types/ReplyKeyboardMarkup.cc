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
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A KeyboardButton based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return KeyboardButton
 */
ReplyKeyboardMarkup ReplyKeyboardMarkup::fromJson(Json::Value Data) {
    std::vector<std::vector<KeyboardButton>> keyboardbuttons;
    for(int i=0;i<Data["photos"].size();i++){
        std::vector<KeyboardButton> keyboardbutton;
        for(int j=0;j<Data["photos"][i].size();j++){
            keyboardbutton.push_back(KeyboardButton::fromJson(Data["keyboard"][i]));
        }
        keyboardbuttons.push_back(keyboardbutton);
    }



    ReplyKeyboardMarkup ret(keyboardbuttons);

    if(Data.isMember("resize_keyboard")){
        ret.setResize_keyboard(Data["resize_keyboard"].asBool());
    }
    if(Data.isMember("one_time_keyboard")){
        ret.setOne_time_keyboard(Data["one_time_keyboard"].asBool());
    }
    if(Data.isMember("selective")){
        ret.setSelective(Data["selective"].asBool());
    }


    return ret;
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
