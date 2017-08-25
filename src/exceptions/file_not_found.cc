//
// Created by norbert on 21.08.17.
//

#include "exceptions/file_not_found.h"

using namespace yatbcpp;

file_not_found::file_not_found(std::string message) : message(message) {
    //TODO only on debug build
//    using namespace std;
//    cerr << message << endl;
}
