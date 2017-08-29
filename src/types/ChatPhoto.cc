#include <string>
#include "types/ChatPhoto.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ChatPhoto::ChatPhoto(std::string small_file_id, std::string big_file_id) : small_file_id(small_file_id), big_file_id(big_file_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &ChatPhoto::getSmall_file_id() const {
    return small_file_id;
}

const string &ChatPhoto::getBig_file_id() const {
    return big_file_id;
}
