//
// Created by norbert on 21.08.17.
//

#include <ostream>
#include <exceptions/curl_error.h>
namespace yatbcpp {

    std::ostream& operator<< (std::ostream &o,const curl_error& curlError) {
        using namespace std;
        return o << "CURL Error Occured <<" << curlError.errorcode<< " | " << curlError.message << ">>";
    }
    std::ostream& operator<< (std::ostream &o,const curl_error* curlError) {
        return o<<*curlError;
    }

}