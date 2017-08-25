//
// Created by norbert on 21.08.17.
//

#include <iostream>
#include "exceptions/telegram_api_error.h"

using namespace yatbcpp;

telegram_api_error::telegram_api_error(int errorcode, std::string message) : errorcode(errorcode), message(message) {
    std::cerr << this << std::endl;
}
