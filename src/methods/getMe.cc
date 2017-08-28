


#include <json/json.h>
#include "methods/telegram_method.h"
#include "methods/getMe.h"

using namespace std;
using namespace yatbcpp;


getMe::getMe() : telegram_method("getMe")
{

}

//template <> Json::Value yatbcpp::toJson(getMe getme){
/**
 * Get Me does not Require any arguments, an empty json object is generated
 * @return
 */
Json::Value getMe::toJson(){
    Json::Value Nada;
    return Nada;
}



