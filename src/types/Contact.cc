#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
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
