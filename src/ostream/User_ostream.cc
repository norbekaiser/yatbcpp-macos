//
// Created by norbert on 19.08.17.
//

#include <ostream>
#include <types/User.h>

namespace yatbcpp{
    std::ostream& operator<< (std::ostream& o,const yatbcpp::User& U){
        using namespace std;
        o << " User::id "            << U.id;
        o << " User::first_name "    << U.first_name;
//        o << " User::last_name "     << U.last_name;
//        o << " User::username "      << U.username;
//        o << " User::language_code " << U.language_code;
        return o;
    }
}