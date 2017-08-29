////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Message.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A Message based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Message
     */
    template<> Message fromJson(Json::Value Data) {
        if (!Data.isMember("message_id")) {
            //message_id is missing
            throw essential_key_missing("Message::message_id is missing");
        }
        if (!Data.isMember("date")) {
            throw essential_key_missing("Message::date is missing");
        }
        if (!Data.isMember("chat")) {
            throw essential_key_missing("Message::chat is missing");
        }

        int message_id = Data["message_id"].asInt();
        int date = Data["date"].asInt();
        Chat chat = fromJson<Chat>(Data["chat"]);

        Message ret(message_id, date, chat);
        //Additional Data parsing
        if (Data.isMember("from")) {
            User U = yatbcpp::fromJson<User>(Data["from"]);
            ret.setFrom(U);
        }
        if (Data.isMember("forward_from")) {
            User U = yatbcpp::fromJson<User>(Data["forward_from"]);
            ret.setForward_from(U);
        }
        if (Data.isMember("forward_from_chat")) {
            Chat C = fromJson<Chat>(Data["forward_from_chat"]);
            ret.setForward_from_chat(C);
        }
        if (Data.isMember("forward_from_message_id")) {
            ret.setForward_from_message_id(Data["forward_from_message_id"].asInt());
        }
        if (Data.isMember("forward_signature")) {
            ret.setForward_signature(Data["forward_signature"].asString());
        }
        if (Data.isMember("forward_date")) {
            ret.setForward_date(Data["forward_date"].asInt());
        }
        //todo reply to message
        if (Data.isMember("edit_date")) {
            ret.setEdit_date(Data["edit_date"].asInt());
        }
        if (Data.isMember("author_signature")) {
            ret.setAuthor_signature(Data["author_signature"].asString());
        }
        if (Data.isMember("text")) {
            ret.setText(Data["text"].asString());
        }
        if (Data.isMember("entities")) {
            for (int i = 0; i < Data["entities"].size(); i++) {
                Json::Value small_entity;
                small_entity = Data["entities"][i];
                MessageEntity messageEntity = fromJson<MessageEntity>(small_entity);
                ret.addEntity(messageEntity);
            }
        }
        if (Data.isMember("audio")) {
            Audio A = yatbcpp::fromJson<Audio>(Data["audio"]);
            ret.setAudio(A);
        }
        if (Data.isMember("document")) {
            ret.setDocument(fromJson<Document>(Data["document"]));
        }
        if (Data.isMember("photo")) {
            for (int i = 0; i < Data["photo"].size(); i++) {
                ret.addPhoto(fromJson<PhotoSize>(Data["photo"][i]));
            }
        }
        //todo missing sticker
        if (Data.isMember("video")) {
            ret.setVideo(fromJson<Video>(Data["video"]));
        }
        if (Data.isMember("voice")) {
            ret.setVoice(fromJson<Voice>(Data["voice"]));
        }
        if (Data.isMember("video_note")) {
            ret.setVideo_note(fromJson<VideoNote>(Data["video_note"]));
        }
        if (Data.isMember("new_chat_members")) {
            for (int i = 0; i < Data["new_chat_members"].size(); i++) {
                ret.addNew_chat_members(yatbcpp::fromJson<User>(Data["new_chat_members"][i]));
            }
        }
        if (Data.isMember("caption")) {
            ret.setCaption(Data["caption"].asString());
        }
        if (Data.isMember("contact")) {
            ret.setContact(fromJson<Contact>(Data["contact"]));
        }
        if (Data.isMember("location")) {
            ret.setLocation(fromJson<Location>(Data["location"]));
        }
        if (Data.isMember("venue")) {
            ret.setVenue(fromJson<Venue>(Data["venue"]));
        }
        if (Data.isMember("new_chat_member")) {
            ret.setNew_chat_member(yatbcpp::fromJson<User>(Data["new_chat_member"]));
        }
        if (Data.isMember("left_chat_member")) {
            ret.setLeft_chat_member(yatbcpp::fromJson<User>(Data["left_chat_member"]));
        }
        if (Data.isMember("new_chat_title")) {
            ret.setNew_chat_title(Data["new_chat_title"].asString());
        }
        if (Data.isMember("new_chat_photo")) {
            for (int i = 0; i < Data["new_chat_photo"].size(); i++) {
                ret.addNew_chat_photo(fromJson<PhotoSize>(Data["new_chat_photo"][i]));
            }
        }
        if (Data.isMember("delete_chat_photo")) {
            ret.setDelete_chat_photo(Data["delete_chat_photo"].asBool());
        }
        if (Data.isMember("group_chat_created")) {
            ret.setGroup_chat_created(Data["group_chat_created"].asBool());
        }
        if (Data.isMember("supergroup_chat_created")) {
            ret.setSupergroup_chat_created(Data["supergroup_chat_created"].asBool());
        }
        if (Data.isMember("channel_chat_created")) {
            ret.setChannel_chat_created(Data["channel_chat_created"].asBool());
        }
        if (Data.isMember("migrate_to_chat_id")) {
            ret.setMigrate_to_chat_id(Data["migrate_to_chat_id"].asLargestInt());
        }
        if (Data.isMember("migrate_from_chat_id")) {//not quite sure if sufficient from spave
            ret.setMigrate_from_chat_id(Data["migrate_from_chat_id"].asLargestInt());
        }
        //pinned message, invoice, sucessfull payment


        return ret;
    }
}