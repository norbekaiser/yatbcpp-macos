#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <json/json.h>
#include <inc/exceptions/telegram_api_error.h>
#include "types/PhotoSize.h"
#include "exceptions/essential_key_missing.h"
#include "types/UserProfilePhotos.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UserProfilePhotos::UserProfilePhotos(int total_count, std::vector<std::vector<PhotoSize>> photos) : total_count(total_count) , photos(photos)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A File based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return File Voice
 */
UserProfilePhotos UserProfilePhotos::fromJson(Json::Value Data) {
    if(!Data.isMember("total_count")){
        throw essential_key_missing("UserProfilePhotos::total_count is missing");
    }

    if(!Data.isMember("photos")){
        throw essential_key_missing("UserProfilePhotos::photos is missing");
    }

    int total_count = Data["total_count"].asInt();
    std::vector<std::vector<PhotoSize>> photos;
    //ok make sure that each photo maximal has 4 photosizes each
    for(int i=0;i<Data["photos"].size();i++){
        std::vector<PhotoSize> photo;
        for(int j=0;j<Data["photos"][i].size();j++){
            photo.push_back(PhotoSize::fromJson(Data["photos"][i]));
        }
        if(photo.size()>4){
            throw telegram_api_error(0,"More than 4 photo sizes for a photo have been found, please check telegram api for changes");
            //Trow something like api error?
        }
        photos.push_back(photo);
    }

    UserProfilePhotos ret(total_count,photos);


    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int UserProfilePhotos::getTotal_count() const {
    return total_count;
}

const vector<vector<PhotoSize>> &UserProfilePhotos::getPhotos() const {
    return photos;
}

