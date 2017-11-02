#include <iostream>
#include "types/InlineQueryResultCachedVoice.h"

using namespace yatbcpp;
using namespace std;

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(std::string id,std::string voice_file_id,std::string title):
        InlineQueryResult("voice",id),
        voice_file_id(voice_file_id), title(title)
{

}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(const InlineQueryResultCachedVoice& InlineQueryResultCachedVoice):
    InlineQueryResult(InlineQueryResultCachedVoice.type,InlineQueryResultCachedVoice.id),
    voice_file_id(InlineQueryResultCachedVoice.voice_file_id), title(InlineQueryResultCachedVoice.title)
{
    caption = InlineQueryResultCachedVoice.caption;
}


Json::Value InlineQueryResultCachedVoice::toJson(){
    std::cout << "VoiceJSON" << std::endl;
    Json::Value Outgoing;
    Outgoing["type"] = getType();//since this is inherited, get it from above?
    Outgoing["id"] = getId();
    Outgoing["voice_file_id"] = getVoice_file_id();
    Outgoing["title"] = getTitle();
    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    //TODO reply markup and input message content
    return  Outgoing;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &InlineQueryResultCachedVoice::getVoice_file_id() const {
    return voice_file_id;
}

const string &InlineQueryResultCachedVoice::getTitle() const {
    return title;
}

const optional<string> &InlineQueryResultCachedVoice::getCaption() const {
    return caption;
}
