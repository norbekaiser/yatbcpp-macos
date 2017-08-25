//
// Created by norbert on 21.08.17.
//

#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <inc/types/Message.h>
#include <iostream>
#include "types/sendMessage.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Since variant would require gcc7 or above, and i love my ci, yeah it is somethink like that,
// will probably change very often

sendMessage::sendMessage(Chat C, std::string text) : chat_id(to_string(C.getId())), text(text)
{
//    chatid = C.getId();
    escape_text_string();
}

sendMessage::sendMessage(int chat_id, std::string text) : chat_id(to_string(chat_id)) , text(text)
{
//    chatid = chat_id;
    escape_text_string();
}

sendMessage::sendMessage(string chat_id, std::string text) : chat_id(chat_id) , text(text)
{
    escape_text_string();
}

//hoffentlich geht das nich bei fast leeren strings kaputt oder so
void sendMessage::escape_text_string() {
//    cout << "Parsing an " << text.length() << " long text";
    for(int i=text.length();i>0;i--){
//        cout << "Itterating::" << i << endl;
        if(text[i]==' '){
//            cout << "Found an empty space at "<< i << endl;
            text.erase(i,1);
            text.insert(i,"%20");
            //since going down, index might be still intact
//            i+=2;//added 3 more things, index might be updated
        }

    }
    cout << text << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sendMessage::setParse_mode(const optional<string> &parse_mode) {
    sendMessage::parse_mode = parse_mode;
}

void sendMessage::setDisable_web_page_preview(const optional<bool> &disable_web_page_preview) {
    sendMessage::disable_web_page_preview = disable_web_page_preview;
}

void sendMessage::setDisable_notification(const optional<bool> &disable_notification) {
    sendMessage::disable_notification = disable_notification;
}

void sendMessage::setReply_to_message_id(const optional<int> &reply_to_message_id) {
    sendMessage::reply_to_message_id = reply_to_message_id;
}

void sendMessage::setReply_to_message_id(const Message M) {
    sendMessage::reply_to_message_id = M.getMessage_id();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &sendMessage::getChat_id() const {
    return chat_id;
}

const string &sendMessage::getText() const {
    return text;
}

const optional<string> &sendMessage::getParse_mode() const {
    return parse_mode;
}

const optional<bool> &sendMessage::getDisable_web_page_preview() const {
    return disable_web_page_preview;
}

const optional<bool> &sendMessage::getDisable_notification() const {
    return disable_notification;
}

const optional<int> &sendMessage::getReply_to_message_id() const {
    return reply_to_message_id;
}

