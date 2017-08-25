//
// Created by norbert on 18.08.17.
//

#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/Update.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Update::Update(int update_id) : update_id(update_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns An Update based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Update
 */
Update Update::fromJson(Json::Value Data) {
    //Checking for essential fields
    if(!Data.isMember("update_id")){
        throw essential_key_missing("Update::update_id is missing");
    }
    //Extracting the essential information
    int update_id = Data["update_id"].asInt();
    //Creating the for return created object
    Update ret(update_id);
    //Adding Optional/Additional Information
    if(Data.isMember("message")){
//        Json::Value mData= Data["message"];
//        Message M= Message::fromJson(mData);
        Message M = Message::fromJson(Data["message"]);
        ret.setMessage(M);
    }
    if(Data.isMember("edited_message")){
//        Json::Value mData= Data["edited_message"];
//        Message M= Message::fromJson(mData);
        Message M = Message::fromJson(Data["edited_message"]);
        ret.setMessage(M);
    }
    if(Data.isMember("channel_post")){
//        Json::Value mData= Data["channel_post"];
//        Message M= Message::fromJson(mData);
        Message M = Message::fromJson(Data["channel_post"]);
        ret.setMessage(M);
    }
    if(Data.isMember("edited_channel_post")){
//        Json::Value mData= Data["edited_channel_post"];
//        Message M= Message::fromJson(mData);
        Message M = Message::fromJson(Data["edited_channel_post"]);
        ret.setMessage(M);
    }
    //Query comming one day to

    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Update::setMessage(const optional<Message> &message) {
    Update::message = message;
}

void Update::setEdited_message(const optional<Message> &edited_message) {
    Update::edited_message = edited_message;
}

void Update::setChannel_post(const optional<Message> &channel_post) {
    Update::channel_post = channel_post;
}

void Update::setEdited_channel_post(const optional<Message> &edited_channel_post) {
    Update::edited_channel_post = edited_channel_post;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Update::getUpdate_id() const {
    return update_id;
}

const optional<Message> &Update::getMessage() const {
    return message;
}

const optional<Message> &Update::getEdited_message() const {
    return edited_message;
}

const optional<Message> &Update::getChannel_post() const {
    return channel_post;
}

const optional<Message> &Update::getEdited_channel_post() const {
    return edited_channel_post;
}
