//
// Created by norbert on 21.08.17.
//

#include <ostream>
#include <exceptions/telegram_api_error.h>
namespace yatbcpp {

    std::ostream& operator<< (std::ostream &o,const telegram_api_error& telegramApiError) {
        using namespace std;
        return o << "Telegram Api Error EXCEPTION<<" << telegramApiError.errorcode<< " | " << telegramApiError.message << ">>";
    }
    std::ostream& operator<< (std::ostream &o,const telegram_api_error* telegramApiError) {
        return o<<*telegramApiError;
    }

}