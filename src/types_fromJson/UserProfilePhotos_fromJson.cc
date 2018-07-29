////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From JSON Specialication                                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <json/json.h>
#include "types/telegram_type.h"
#include "exceptions/essential_key_missing.h"
#include "exceptions/telegram_api_error.h"
#include "types/UserProfilePhotos.h"

using namespace std;

namespace yatbcpp {
/**
 * Returns A File based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return File Voice
 */
    template<> UserProfilePhotos fromJson(Json::Value Data) {
        if (!Data.isMember("total_count")) {
            throw essential_key_missing("UserProfilePhotos::total_count is missing");
        }

        if (!Data.isMember("photos")) {
            throw essential_key_missing("UserProfilePhotos::photos is missing");
        }

        std::int32_t total_count = Data["total_count"].asInt();
        std::vector<std::vector<PhotoSize>> photos;
//        photos.reserve(Data["photos"].size());
        //ok make sure that each photo maximal has 4 photosizes each
        for (int i = 0; i < Data["photos"].size(); i++) {
            std::vector<PhotoSize> photo;
//            photo.reserve(Data["photos"][i].size());
            for (int j = 0; j < Data["photos"][i].size(); j++) {
                photo.push_back(fromJson<PhotoSize>(Data["photos"][i]));
            }
            if (photo.size() > 4) {
                throw telegram_api_error(0,"More than 4 photo sizes for a photo have been found, please check telegram api for changes");
                //Trow something like api error?
            }
            photos.push_back(photo);
        }

        UserProfilePhotos ret(total_count, photos);


        return ret;
    }
}
