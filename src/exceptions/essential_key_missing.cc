//
// Created by norbert on 21.08.17.
//

#include "exceptions/essential_key_missing.h"

using namespace yatbcpp;

essential_key_missing::essential_key_missing(std::string message) : message(message) {
    //TODO only on debug build
//    using namespace std;
//    cerr << message << endl;
}