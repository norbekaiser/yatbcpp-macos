
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "methods/sendLocation.h"

using namespace std;
using namespace yatbcpp;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sendLocation::sendLocation(Chat C,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(to_string(C.getId())), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}

sendLocation::sendLocation(int chat_id,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(to_string(chat_id)), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}

sendLocation::sendLocation(string chat_id,Location location) :
        telegram_methodJSON("sendLocation"),
        chat_id(chat_id), latitude(location.getLatitude()), longitude(location.getLongitude())
{
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value sendLocation::toJson() {
    Json::Value Outgoing;
    Outgoing["chat_id"] = getChat_id();
    Outgoing["latitude"] = getLatitude();
    Outgoing["longitude"] = getLongitude();

    if(getLivePeriod()){
        Outgoing["live_period"] = getLivePeriod().value();
    }
    if(getDisable_notification()){
        Outgoing["disable_notification"] = getDisable_notification().value();
    }
    if(getReply_to_message_id()){
        Outgoing["reply_to_message_id"] = getReply_to_message_id().value();
    }

    return Outgoing;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void sendLocation::setLive_period(const optional<unsigned int> &live_period) {
    sendLocation::live_period = live_period;
}

void sendLocation::setDisable_notification(const std::optional<bool> &disable_notification) {
    sendLocation::disable_notification = disable_notification;
}

void sendLocation::setReply_to_message_id(const std::optional<int> &reply_to_message_id) {
    sendLocation::reply_to_message_id = reply_to_message_id;
}


/**
 * Sets an ReplyKeyboardMarkup
 * @param RKM
 */
void sendLocation::setReplyMarkup(const ReplyKeyboardMarkup RKM){
    sendLocation::reply_markup = RKM;
}

/**
 * Sets an ReplyKeyboardRemove
 * @param RKR
 */
void sendLocation::setReplyMarkup(const ReplyKeyboardRemove RKR){
    sendLocation::reply_markup = RKR;
}

/**
 * Sets an ForceReply
 * @param FR
 */
void sendLocation::setReplyMarkup(const ForceReply FR){
    sendLocation::reply_markup = FR;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendLocation::getChat_id() const {
    return chat_id;
}

const float &sendLocation::getLatitude() const {
    return latitude;
}

const float &sendLocation::getLongitude() const {
    return longitude;
}

const optional<unsigned int> &sendLocation::getLivePeriod() const {
    return live_period;
}

const optional<bool> &sendLocation::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendLocation::getReply_to_message_id() const {
    return reply_to_message_id;
}

const optional<ReplyMarkup> &sendLocation::getReply_markup() const {
    return reply_markup;
}
