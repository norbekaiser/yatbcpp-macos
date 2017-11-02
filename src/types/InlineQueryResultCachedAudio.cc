#include <iostream>
#include "types/InlineQueryResultCachedAudio.h"

using namespace yatbcpp;
using namespace std;

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(std::string id, std::string audio_file_id):
        InlineQueryResult("audio",id),
        audio_file_id(audio_file_id)
{

}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(const InlineQueryResultCachedAudio& InlineQueryResultCachedAudio): 
    InlineQueryResult(InlineQueryResultCachedAudio.type,InlineQueryResultCachedAudio.id), 
    audio_file_id(InlineQueryResultCachedAudio.audio_file_id)
{
    caption = InlineQueryResultCachedAudio.caption;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value InlineQueryResultCachedAudio::toJson(){
    std::cout << "VoiceJSON" << std::endl;
    Json::Value Outgoing;
    Outgoing["type"] = getType();//since this is inherited, get it from above?
    Outgoing["id"] = getId();
    Outgoing["audio_file_id"] = getAudio_file_id();
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

const string &InlineQueryResultCachedAudio::getAudio_file_id() const {
    return audio_file_id;
}

const optional<string> &InlineQueryResultCachedAudio::getCaption() const {
    return caption;
}
