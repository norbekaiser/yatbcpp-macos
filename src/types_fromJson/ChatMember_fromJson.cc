////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/ChatMember.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A ChatMember based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed ChatMember
     */
    template<> ChatMember fromJson(Json::Value Data) {
        if (!Data.isMember("user")) {
            throw essential_key_missing("ChatMember::small_file_id is missing");
        }
        if (!Data.isMember("status")) {
            throw essential_key_missing("ChatMember::big_file_id is missing");
        }

        //    yatbcpp<User>::fromJson()
        User user = yatbcpp::fromJson<User>(Data["user"]);
        string status = Data["status"].asString();

        ChatMember ret(user, status);

        if (Data.isMember("until_date")) {
            ret.setUntil_date(Data["until_date"].asInt());
        }
        if (Data.isMember("can_be_edited")) {
            ret.setCan_be_edited(Data["can_be_edited"].asBool());
        }
        if (Data.isMember("can_change_info")) {
            ret.setCan_change_info(Data["can_change_info"].asBool());
        }
        if (Data.isMember("can_post_messages")) {
            ret.setCan_post_messages(Data["can_post_messages"].asBool());
        }
        if (Data.isMember("can_edit_messages")) {
            ret.setCan_edit_messages(Data["can_edit_messages"].asBool());
        }
        if (Data.isMember("can_delete_messages")) {
            ret.setCan_delete_messages(Data["can_delete_messages"].asBool());
        }
        if (Data.isMember("can_invite_users")) {
            ret.setCan_invite_users(Data["can_invite_users"].asBool());
        }
        if (Data.isMember("can_restrict_members")) {
            ret.setCan_restrict_members(Data["can_restrict_members"].asBool());
        }
        if (Data.isMember("can_pin_messages")) {
            ret.setCan_pin_messages(Data["can_pin_messages"].asBool());
        }
        if (Data.isMember("can_promote_members")) {
            ret.setCan_promote_members(Data["can_promote_members"].asBool());
        }
        if (Data.isMember("can_send_messages")) {
            ret.setCan_send_messages(Data["can_send_messages"].asBool());
        }
        if (Data.isMember("can_send_media_messages")) {
            ret.setCan_send_media_messages(Data["can_send_media_messages"].asBool());
        }
        if (Data.isMember("can_send_other_messages")) {
            ret.setCan_send_other_messages(Data["can_send_other_messages"].asBool());
        }
        if (Data.isMember("can_add_web_page_previews")) {
            ret.setCan_add_web_page_previews(Data["can_add_web_page_previews"].asBool());
        }
        return ret;
    }
}
