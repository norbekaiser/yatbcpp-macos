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
#ifndef YATBCPP_TELEGRAM_METHODMULTIPART_H
#define YATBCPP_TELEGRAM_METHODMULTIPART_H

#include "curl/curl.h"
#include <json/json.h>
#include "../exceptions/telegram_api_error.h"
#include "../exceptions/curl_error.h"
#include "../types/telegram_type.h"
#include "../exceptions/essential_key_missing.h"
#include "../bot/Token.h"

namespace yatbcpp{
    /**
     * Required for Methods which can be serialized to a Multipart request, for file uploading use multipart, file types are then considered files to be uploaded
     * @tparam RETURNTYPE
     */
    template <class RETURNTYPE> class telegram_methodMultipart{
    public:

        telegram_methodMultipart(std::string functionname) : functionname(functionname){}

        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *stringptr){
            using namespace std;
            ((string*)stringptr)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }



        static RETURNTYPE perform_requestMultipart(Token T, telegram_methodMultipart<RETURNTYPE> &method_body){
            using namespace std;
            string api_url ( "https://api.telegram.org/bot" + T.getToken() + "/" + method_body.getFunctionname() );
            string readBuffer;
            Json::Reader reader;
            Json::Value Response;
            struct curl_slist * curl_header_list =NULL;
            curl_header_list = curl_slist_append( curl_header_list , "Content-Type: multipart/form-data" );

            struct curl_httppost *uploadPost=NULL;
            struct curl_httppost *endptr=NULL;

            method_body.add_to_post(&uploadPost,&endptr);

            CURL* curl = curl_easy_init();

            curl_easy_setopt(curl,CURLOPT_URL,api_url.c_str());
            curl_easy_setopt(curl,CURLOPT_HTTPHEADER,curl_header_list);
            curl_easy_setopt(curl,CURLOPT_HTTPPOST,uploadPost);
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
                curl_formfree(uploadPost);
                return yatbcpp::fromJson<RETURNTYPE>(Response["result"]);
            }
            else{
                curl_formfree(uploadPost);
                curl_easy_cleanup(curl);
                curl_slist_free_all(curl_header_list);
                throw telegram_api_error(Response["error_code"].asInt(),Response["description"].asString());
            }


        }
        /**
         * Method Required for derived classes so they can be made into Multipart object
         * The Post Parts have to be added in it , upon end of request it is deleted in perform_requestMultipart
         * @return
         */
        virtual void add_to_post(struct curl_httppost **start,struct curl_httppost **end){}

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


#endif //YATBCPP_TELEGRAM_METHODMULTIPART_H
