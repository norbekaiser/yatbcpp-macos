//
// Created by norbert on 23.08.17.
//

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/Contact.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Contact::Contact(std::string phone_number, std::string first_name) : phone_number(phone_number), first_name(first_name)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Contact based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Contact
 */
Contact Contact::fromJson(Json::Value Data) {
    if(!Data.isMember("phone_number")){
        throw essential_key_missing("Contact::file_id is missing");
    }
    if(!Data.isMember("first_name")){
        throw essential_key_missing("Contact::duration is missing");
    }
    std::string phone_number = Data["phone_number"].asString();
    std::string first_name = Data["first_name"].asString();

    Contact ret(phone_number,first_name);

    if(Data.isMember("last_name")){
        ret.setLast_name(Data["last_name"].asString());
    }
    if(Data.isMember("user_id")){
        ret.setUser_id(Data["user_id"].asInt());
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Contact::setLast_name(const optional<string> &last_name) {
    Contact::last_name = last_name;
}

void Contact::setUser_id(const optional<int> &user_id) {
    Contact::user_id = user_id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


const string &Contact::getPhone_number() const {
    return phone_number;
}

const string &Contact::getFirst_name() const {
    return first_name;
}

const optional<string> &Contact::getLast_name() const {
    return last_name;
}

const optional<int> &Contact::getUser_id() const {
    return user_id;
}
