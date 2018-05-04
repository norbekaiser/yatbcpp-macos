//    Copyright (c) 2017,2018 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.
//
// Created by norbert on 18.08.17.
//

#ifndef YATBCPP_MESSAGE_H
#define YATBCPP_MESSAGE_H

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "User.h"
#include "Chat.h"
#include "MessageEntity.h"
#include "Audio.h"
#include "Document.h"
#include "Video.h"
#include "Voice.h"
#include "VideoNote.h"
#include "Contact.h"
#include "Location.h"
#include "Venue.h"


namespace yatbcpp{
    /** See also https://core.telegram.org/bots/api#message */
    class Message{
    public:
        Message(int message_id,int date,Chat chat);
        
        Message(const Message& Message);

        void setFrom(const std::optional<User> &from);

        void setForward_from(const std::optional<User> &forward_from);

        void setForward_from_chat(const std::optional<Chat> &forward_from_chat);

        void setForward_from_message_id(const std::optional<int> &forward_from_message_id);

        void setForward_signature(const std::optional<std::string> &forward_signature);

        void setForward_date(const std::optional<int> &forward_date);

        void setEdit_date(const std::optional<int> &edit_date);

        void setAuthor_signature(const std::optional<std::string> &author_signature);

        void setText(const std::optional<std::string> &text);

        void addEntity(const MessageEntity &messageEntity);

        void setAudio(const std::optional<Audio> &audio);

        void setDocument(const std::optional<Document> &document);

        void addPhoto(const PhotoSize &Photo);

        void setVideo(const std::optional<Video> &video);

        void setVoice(const std::optional<Voice> &voice);

        void setVideo_note(const std::optional<VideoNote> &video_note);

        void addNew_chat_members(const User &new_chat_member);

        void setCaption(const std::optional<std::string> &caption);

        void setContact(const std::optional<Contact> &contact);

        void setLocation(const std::optional<Location> &location);

        void setVenue(const std::optional<Venue> &venue);

        void setNew_chat_member(const std::optional<User> &new_chat_member);

        void setLeft_chat_member(const std::optional<User> &left_chat_member);

        void setNew_chat_title(const std::optional<std::string> &new_chat_title);

        void addNew_chat_photo(const PhotoSize &newchatphoto);

        void setDelete_chat_photo(const std::optional<bool> &delete_chat_photo);

        void setGroup_chat_created(const std::optional<bool> &group_chat_created);

        void setSupergroup_chat_created(const std::optional<bool> &supergroup_chat_created);

        void setChannel_chat_created(const std::optional<bool> &channel_chat_created);

        void setMigrate_to_chat_id(const std::optional<long> &migrate_to_chat_id);

        void setMigrate_from_chat_id(const std::optional<long> &migrate_from_chat_id);


        int getMessage_id() const;

        const std::optional<User> &getFrom() const;

        int getDate() const;

        const Chat &getChat() const;

        const std::optional<User> &getForward_from() const;

        const std::optional<Chat> &getForward_from_chat() const;

        const std::optional<int> &getForward_from_message_id() const;

        const std::optional<std::string> &getForward_signature() const;

        const std::optional<int> &getForward_date() const;

        const std::optional<int> &getEdit_date() const;

        const std::optional<std::string> &getAuthor_signature() const;

        const std::optional<std::string> &getText() const;

        const std::vector<MessageEntity> &getEntities() const;

        const std::optional<Audio> &getAudio() const;

        const std::optional<Document> &getDocument() const;

        const std::vector<PhotoSize> &getPhoto() const;

        const std::optional<Video> &getVideo() const;

        const std::optional<Voice> &getVoice() const;

        const std::optional<VideoNote> &getVideo_note() const;

        const std::vector<User> &getNew_chat_members() const;

        const std::optional<std::string> &getCaption() const;

        const std::optional<Contact> &getContact() const;

        const std::optional<Location> &getLocation() const;

        const std::optional<Venue> &getVenue() const;

        const std::optional<User> &getNew_chat_member() const;

        const std::optional<User> &getLeft_chat_member() const;

        const std::optional<std::string> &getNew_chat_title() const;

        const std::vector<PhotoSize> &getNew_chat_photo() const;

        const std::optional<bool> &getDelete_chat_photo() const;

        const std::optional<bool> &getGroup_chat_created() const;

        const std::optional<bool> &getSupergroup_chat_created() const;

        const std::optional<bool> &getChannel_chat_created() const;

        const std::optional<long> &getMigrate_to_chat_id() const;

        const std::optional<long> &getMigrate_from_chat_id() const;


    private:
        /**Unique message identifier inside this chat*/
        int message_id;
        /**Optional. Sender, empty for messages sent to channels*/
        std::optional<User> from;//Optional
        /**Date the message was sent in Unix time*/
        int date;
        /**onversation the message belongs to*/
        Chat chat;
        /**Optional. For forwarded messages, sender of the original message*/
        std::optional<User> forward_from;
        /**Optional. For messages forwarded from channels, information about the original channel*/
        std::optional<Chat> forward_from_chat;
        /**Optional. For messages forwarded from channels, identifier of the original message in the channel*/
        std::optional<int> forward_from_message_id;
        /**Optional. For messages forwarded from channels, signature of the post author if present*/
        std::optional<std::string> forward_signature;
        /**Optional. For forwarded messages, date the original message was sent in Unix time*/
        std::optional<int> forward_date;
//        Optional. For replies, the original message. Note that the Message object in this field will not contain further reply_to_message fields even if it itself is a reply.
//        std::optional<Message*> reply_to_message;//=NULL;//Optional//sigh auch das noch//naja dann als pointer, ggf adden?
        /**Optional. Date the message was last edited in Unix time*/
        std::optional<int> edit_date;
        /**Optional. Signature of the post author for messages in channels*/
        std::optional<std::string> author_signature;
        /**Optional. For text messages, the actual UTF-8 text of the message, 0-4096 characters.*/
        std::optional<std::string> text;
        /**Optional. For text messages, special entities like usernames, URLs, bot commands, etc. that appear in the text*/
        std::vector<MessageEntity> entities;
        /**Optional. Message is an audio file, information about the file*/
        std::optional<Audio> audio;
        /**Optional. Message is a general file, information about the file*/
        std::optional<Document> document;
        /**Optional. Message is a photo, available sizes of the photo*/
        std::vector<PhotoSize> photo;
        /**Optional. Message is a video, information about the video*/
        std::optional<Video> video;
        /**Optional. Message is a voice message, information about the file*/
        std::optional<Voice> voice;
        /**Optional. Message is a video note, information about the video message*/
        std::optional<VideoNote> video_note;
        /**Optional. New members that were added to the group or supergroup and information about them (the bot itself may be one of these members)*/
        std::vector<User> new_chat_members;
        /**Optional. Caption for the document, photo or video, 0-200 characters*/
        std::optional<std::string> caption;
        /**Optional. Message is a shared contact, information about the contact*/
        std::optional<Contact> contact;
        /**Optional. Message is a shared location, information about the location*/
        std::optional<Location> location;
        /**Optional. Message is a venue, information about the venue*/
        std::optional <Venue> venue;
        /**Optional. A new member was added to the group, information about them (this member may be the bot itself)*/
        std::optional<User> new_chat_member;
        /**Optional. A member was removed from the group, information about them (this member may be the bot itself)*/
        std::optional<User> left_chat_member;
        /**Optional. A chat title was changed to this value*/
        std::optional<std::string> new_chat_title;
        /**Optional. A chat photo was change to this value*/
        std::vector<PhotoSize> new_chat_photo;
        /**Optional. Service message: the chat photo was deleted*/
        std::optional<bool> delete_chat_photo;
        /**Optional. Service message: the group has been created*/
        std::optional<bool> group_chat_created;
        /**Optional. Service message: the supergroup has been created. This field can‘t be received in a message coming through updates, because bot can’t be a member of a supergroup when it is created. It can only be found in reply_to_message if someone replies to a very first message in a directly created supergroup.*/
        std::optional<bool> supergroup_chat_created;
        /**Optional. Service message: the channel has been created. This field can‘t be received in a message coming through updates, because bot can’t be a member of a channel when it is created. It can only be found in reply_to_message if someone replies to a very first message in a channel.*/
        std::optional<bool> channel_chat_created;
        /**Optional. The group has been migrated to a supergroup with the specified identifier. This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it. But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.*/
        std::optional<long> migrate_to_chat_id;
        /**Optional. The supergroup has been migrated from a group with the specified identifier. This number may be greater than 32 bits and some programming languages may have difficulty/silent defects in interpreting it. But it is smaller than 52 bits, so a signed 64 bit integer or double-precision float type are safe for storing this identifier.*/
        std::optional<long> migrate_from_chat_id;
        /**Optional. Specified message was pinned. Note that the Message object in this field will not contain further reply_to_message fields even if it is itself a reply.*/
//        std::optional<Message*> pinned_message;
        //todo invoice
        //todo payment




    };

}

#endif //YATBCPP_MESSAGE_H
