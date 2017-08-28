//    Copyright (c) 2017 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.
//
// Created by norbert on 27.08.17.
//

#ifndef YATBCPP_TELEGRAM_METHOD_H
#define YATBCPP_TELEGRAM_METHOD_H

#include "curl/curl.h"
#include <json/json.h>
#include <iostream>
#include "../exceptions/telegram_api_error.h"
#include "../types/telegram_type.h"
#include "../exceptions/essential_key_missing.h" //todo move to cc file as include is else dirty
#include "../bot/Token.h"

namespace yatbcpp{
    template <typename T> Json::Value toJson(T Obj);


    template <class RETURNTYPE> class telegram_method{
    public:
        /**
         * Telegram Method Needs the Token to Send, however might as wellbe returned by bot with read inToken?
         * @param T
         */
//        telegram_method(Token T) : (&T) {}
        telegram_method(std::string functionname) : functionname(functionname){
            //ok das iwie noch meh
//            static_assert(std::is_base_of<RETURNTYPE,telegram_method>::value, "Derived RETURNTYPE is not derived from BaseClass, fromJSON can not be guaranteed");
        }

        /**
         * An outgoing Request needs to be parsable to json so it can be transmitted
         * will throw if nescesary tokens are not present mb
         * @return a Json::Value Representation of the object
         */

        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *stringptr){
            using namespace std;
            ((string*)stringptr)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }



        static RETURNTYPE perform_request(Token T, telegram_method<RETURNTYPE> &method_body){
            std::cerr << "STarting to perform request" << std::endl;
            using namespace std;
            string curl_payload( method_body.toJson().toStyledString() );
//            string curl_payload( "" );
//            toJson<telegram_method<RETURNTYPE>>(method_body);
//            method_body.sies();
            std::cout << "Sending >> " << curl_payload << ">>" << std::endl;
            string api_url ( "https://api.telegram.org/bot"+T.getToken()+"/"+method_body.getFunctionname() );
            string readBuffer;
            Json::Reader reader;
            Json::Value Response;
            struct curl_slist * curl_header_list =NULL;
            curl_header_list = curl_slist_append(curl_header_list,"Content-Type: application/json");
            CURL* curl = curl_easy_init();

            curl_easy_setopt(curl,CURLOPT_URL,api_url.c_str());
            curl_easy_setopt(curl,CURLOPT_POSTFIELDS,curl_payload.c_str());
            curl_easy_setopt(curl,CURLOPT_HTTPHEADER,curl_header_list);
            curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
            curl_easy_setopt(curl,CURLOPT_WRITEDATA,&readBuffer);

            CURLcode res = curl_easy_perform(curl);
            reader.parse(readBuffer,Response);
            std::cout << "PAYLOAD" << std::endl;
            std::cout <<  curl_payload << std::endl;
            std::cout << "READBUFFER" << std::endl;
            std::cout << readBuffer << std::endl;
            if(Response["ok"].asBool()){
                std::cout << "Trying to Parse" << std::endl;
                return yatbcpp::fromJson<RETURNTYPE>(Response["result"]);
            }
            else{
                std::cout << "Oh No" << std::endl;
                curl_easy_cleanup(curl);
                curl_slist_free_all(curl_header_list);
                throw telegram_api_error(Response["error_code"].asInt(),Response["description"].asString());
            }


        }


//        virtual void sies()=0;
        virtual Json::Value toJson(){}
//        virtual void sies(){
//            std::cerr<< "näy"<< std::endl;
//        }

        const std::string &getFunctionname() const {
            return functionname;
        }

    protected:
        std::string functionname;
    };

}


#endif //YATBCPP_TELEGRAM_METHOD_H
