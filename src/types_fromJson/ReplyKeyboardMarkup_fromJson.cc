////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/ReplyKeyboardMarkup.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A KeyboardButton based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return KeyboardButton
     */
    template<> ReplyKeyboardMarkup fromJson(Json::Value Data) {
        std::vector<std::vector<KeyboardButton>> keyboardbuttons;
        for (int i = 0; i < Data["photos"].size(); i++) {
            std::vector<KeyboardButton> keyboardbutton;
            for (int j = 0; j < Data["photos"][i].size(); j++) {
                keyboardbutton.push_back(fromJson<KeyboardButton>(Data["keyboard"][i]));
            }
            keyboardbuttons.push_back(keyboardbutton);
        }


        ReplyKeyboardMarkup ret(keyboardbuttons);

        if (Data.isMember("resize_keyboard")) {
            ret.setResize_keyboard(Data["resize_keyboard"].asBool());
        }
        if (Data.isMember("one_time_keyboard")) {
            ret.setOne_time_keyboard(Data["one_time_keyboard"].asBool());
        }
        if (Data.isMember("selective")) {
            ret.setSelective(Data["selective"].asBool());
        }


        return ret;
    }
}

