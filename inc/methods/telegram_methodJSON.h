//    Copyright (c) 2017,2018 Norbert Rühl
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
#ifndef YATBCPP_TELEGRAM_METHODJSON_H
#define YATBCPP_TELEGRAM_METHODJSON_H

#include "curl/curl.h"
#include <json/json.h>
#include "../exceptions/telegram_api_error.h"
#include "../exceptions/curl_error.h"
#include "../types/telegram_type.h"
#include "../exceptions/essential_key_missing.h"
#include "../bot/Token.h"

namespace yatbcpp{
    template <typename T> Json::Value toJson(T Obj);

    /**
     * Required for Methods which can be serialized to a json request, for file uploading use multipart, file types are then considered files to be uploaded
     * @tparam RETURNTYPE
     */
    template <class RETURNTYPE> class telegram_methodJSON{
    public:

        telegram_methodJSON(std::string functionname) : functionname(functionname){
            //ok das iwie noch meh
            //static_assert(std::is_base_of<RETURNTYPE,telegram_method>::value, "Derived RETURNTYPE is not derived from BaseClass, fromJSON can not be guaranteed");
        }

        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *stringptr){
            using namespace std;
            ((string*)stringptr)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }



        static RETURNTYPE perform_requestJSON(Token T, telegram_methodJSON<RETURNTYPE> &method_body){
            using namespace std;
            string curl_payload( method_body.toJson().toStyledString() );
            string api_url ( "https://api.telegram.org/bot" + T.getToken() + "/" + method_body.getFunctionname() );
            string readBuffer;
            Json::Reader reader;
            Json::Value Response;
            struct curl_slist * curl_header_list =NULL;
            curl_header_list = curl_slist_append( curl_header_list , "Content-Type: application/json" );
            CURL* curl = curl_easy_init();

            curl_easy_setopt(curl,CURLOPT_URL,api_url.c_str());
            curl_easy_setopt(curl,CURLOPT_POSTFIELDS,curl_payload.c_str());
            curl_easy_setopt(curl,CURLOPT_HTTPHEADER,curl_header_list);
            curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
            curl_easy_setopt(curl,CURLOPT_WRITEDATA,&readBuffer);

            CURLcode res = curl_easy_perform(curl);
            reader.parse(readBuffer,Response);
            if(res!=CURLE_OK){
                throw curl_error(res,curl_easy_strerror(res));
            }
            if(Response["ok"].asBool()){
                curl_slist_free_all(curl_header_list);
                curl_easy_cleanup(curl);
                return yatbcpp::fromJson<RETURNTYPE>(Response["result"]);
            }
            else{
                curl_easy_cleanup(curl);
                curl_slist_free_all(curl_header_list);
                throw telegram_api_error(Response["error_code"].asInt(),Response["description"].asString());
            }


        }
        /**
         * Method Required for derived classes so they can be made into json object
         * @return
         */
        virtual Json::Value toJson(){}

        /**
         * returns the Functionname
         * @return
         */
        const std::string &getFunctionname() const {
            return functionname;
        }

    protected:
        std::string functionname;
    };

}


#endif //YATBCPP_TELEGRAM_METHODJSON_H
