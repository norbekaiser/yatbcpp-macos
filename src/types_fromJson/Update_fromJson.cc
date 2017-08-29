////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/Update.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns An Update based on a Json Object
     * @param Data   a Json Object Containing the necessary and Optional Fields
     * @return Parsed Update
     */
    template<> Update fromJson(Json::Value Data) {
        //Checking for essential fields
        if (!Data.isMember("update_id")) {
            throw essential_key_missing("Update::update_id is missing");
        }
        //Extracting the essential information
        int update_id = Data["update_id"].asInt();
        //Creating the for return created object
        Update ret(update_id);
        //Adding Optional/Additional Information
        if (Data.isMember("message")) {
//        Json::Value mData= Data["message"];
//        Message M= Message::fromJson(mData);
            Message M = fromJson<Message>(Data["message"]);
            ret.setMessage(M);
        }
        if (Data.isMember("edited_message")) {
//        Json::Value mData= Data["edited_message"];
//        Message M= Message::fromJson(mData);
            Message M = fromJson<Message>(Data["edited_message"]);
            ret.setMessage(M);
        }
        if (Data.isMember("channel_post")) {
//        Json::Value mData= Data["channel_post"];
//        Message M= Message::fromJson(mData);
            Message M = fromJson<Message>(Data["channel_post"]);
            ret.setMessage(M);
        }
        if (Data.isMember("edited_channel_post")) {
//        Json::Value mData= Data["edited_channel_post"];
//        Message M= Message::fromJson(mData);
            Message M = fromJson<Message>(Data["edited_channel_post"]);
            ret.setMessage(M);
        }
        //Query comming one day to

        return ret;
    }
}