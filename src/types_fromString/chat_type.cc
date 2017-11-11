////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/chat_type.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A chat_type based on a STL string
     * @param Data   a String Containing the nescesary data
     * @return Parsed chat_type
     */
    template<> chat_type fromString(string Data) {
        if(Data.compare("private")==0){
            return chat_type::Private;
        }
        else if(Data.compare("group")==0){
            return chat_type::Group;
        }
        else if(Data.compare("supergroup")==0){
            return chat_type::Supergroup;
        }
        else if(Data.compare("channel")==0){
            return chat_type::Channel;
        }
        else{
            throw essential_key_missing("chat_type parsable key is not known how to be parsed to");
        }
    }
    
}