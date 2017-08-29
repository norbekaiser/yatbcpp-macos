#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/User.h"
using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

User::User(int id, bool is_bot, string first_name) : id(id), is_bot(is_bot), first_name(first_name)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void User::setLast_name(const optional<string> &last_name) {
    User::last_name = last_name;
}

void User::setUsername(const optional<string> &username) {
    User::username = username;
}

void User::setLanguage_code(const optional<string> &language_code) {
    User::language_code = language_code;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int User::getId() const {
    return id;
}

const string &User::getFirst_name() const {
    return first_name;
}

const optional<string> &User::getLast_name() const {
    return last_name;
}

const optional<string> &User::getUsername() const {
    return username;
}

const optional<string> &User::getLanguage_code() const {
    return language_code;
}



