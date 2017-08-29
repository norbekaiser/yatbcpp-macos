#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
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
