#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/PhotoSize.h"
#include "types/UserProfilePhotos.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UserProfilePhotos::UserProfilePhotos(int32_t total_count, std::vector<std::vector<PhotoSize>> photos):
        total_count(total_count) , photos(photos)
{

}

UserProfilePhotos::UserProfilePhotos(const UserProfilePhotos& UserProfilePhotos):
        total_count(UserProfilePhotos.total_count) , photos(UserProfilePhotos.photos)
{
    
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int32_t  UserProfilePhotos::getTotal_count() const {
    return total_count;
}

const vector<vector<PhotoSize>> &UserProfilePhotos::getPhotos() const {
    return photos;
}

