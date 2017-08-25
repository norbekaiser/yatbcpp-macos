//
// Created by norbert on 21.08.17.
//

#include <ostream>
#include <exceptions/file_not_found.h>
namespace yatbcpp {

    std::ostream& operator<< (std::ostream &o,const file_not_found& fileNotFound) {
        using namespace std;
        return o << "FILE_NOT_FOUND EXCEPTION<<" << fileNotFound.message << ">>";
    }
    std::ostream& operator<< (std::ostream &o,const file_not_found* fileNotFound) {
        return o<<*fileNotFound;
    }

}