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
            Message M = fromJson<Message>(Data["message"]);
            ret.setMessage(M);
        }
        if (Data.isMember("edited_message")) {
            Message M = fromJson<Message>(Data["edited_message"]);
            ret.setEdited_message(M);
        }
        if (Data.isMember("channel_post")) {
            Message M = fromJson<Message>(Data["channel_post"]);
            ret.setChannel_post(M);
        }
        if (Data.isMember("edited_channel_post")) {
            Message M = fromJson<Message>(Data["edited_channel_post"]);
            ret.setEdited_channel_post(M);
        }
        if (Data.isMember("inline_query")) {
            InlineQuery I= fromJson<InlineQuery>(Data["inline_query"]);
            ret.setInlineQuery(I);
        }


        return ret;
    }
}