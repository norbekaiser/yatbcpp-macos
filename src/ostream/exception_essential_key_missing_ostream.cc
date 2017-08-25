//
// Created by norbert on 21.08.17.
//

#include <ostream>
#include <exceptions/essential_key_missing.h>
namespace yatbcpp {

    std::ostream& operator<< (std::ostream &o,const essential_key_missing& essentialKeyMissing) {
        using namespace std;
        return o << "FILE_NOT_FOUND EXCEPTION<<" << essentialKeyMissing.message << ">>";
    }
    std::ostream& operator<< (std::ostream &o,const essential_key_missing* essentialKeyMissing) {
        return o<<*essentialKeyMissing;
    }

}