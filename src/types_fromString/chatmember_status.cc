////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "types/chatmember_status.h"

using namespace std;

namespace yatbcpp {
    /**
     * Returns A chatmember_status based on a STL string
     * @param Data   a String Containing the nescesary data
     * @return Parsed chatmember_status
     */
    template<> chatmember_status fromString(string Data) {
        if(Data.compare("creator")==0){
            return chatmember_status::creator;
        }
        else if(Data.compare("administrator")==0){
            return chatmember_status::administrator;
        }
        else if(Data.compare("member")==0){
            return chatmember_status::member;
        }
        else if(Data.compare("restricted")==0){
            return chatmember_status::restricted;
        }
        else if(Data.compare("left")==0){
            return chatmember_status::left;
        }
        else if(Data.compare("kicked")==0){
            return chatmember_status::kicked;
        }
        else{
            throw essential_key_missing("chatmember_status parsable key is not known how to be parsed to");
        }
    }
    
}