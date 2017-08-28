
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include "types/ReplyKeyboardRemove.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ReplyKeyboardRemove::ReplyKeyboardRemove() : remove_keyboard(true)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ReplyKeyboardRemove::setSelective(const optional<bool> &selective) {
    ReplyKeyboardRemove::selective = selective;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ReplyKeyboardRemove::isRemove_keyboard() const {
    return remove_keyboard;
}

const optional<bool> &ReplyKeyboardRemove::getSelective() const {
    return selective;
}
