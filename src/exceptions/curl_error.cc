//
// Created by norbert on 21.08.17.
//

#include "exceptions/curl_error.h"

using namespace yatbcpp;

curl_error::curl_error(int errorcode, std::string message) : errorcode(errorcode), message(message) {

}
