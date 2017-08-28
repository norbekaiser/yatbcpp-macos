########################################################################################################################
# Yet Another Telegram Bot CPP Library                                                                                 #
########################################################################################################################

cmake_minimum_required(VERSION 3.0)
project(yatbcpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/version.cmake)
message(STATUS "${PROJECT_NAME} Version: " ${yatbcpp_VERSION})

########################################################################################################################
# Verifying Compiler Compability                                                                                       #
########################################################################################################################c
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/check_compilers.cmake)

########################################################################################################################
# Verifying Needed Requirements                                                                                        #
########################################################################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/check_librequirements.cmake)

########################################################################################################################
# Telegram Bot Header Files                                                                                            #
########################################################################################################################
file(GLOB yatbcppBotHeadersList
        "inc/bot/*.h"
)
file(GLOB yatbcppMethodsHeadersList
        "inc/methods/*.h"
)
file(GLOB yatbcppTypesHeadersList
        "inc/types/*.h"
)
file(GLOB yatbcppExceptionsHeadersList
        "inc/exceptions/*.h"
)
########################################################################################################################
# Telegram Bot Source Files                                                                                            #
########################################################################################################################
file(GLOB SOURCE_FILES_OSTREAM_OPERATOR
        "src/ostream/*.cc"
)
set(SOURCE_FILES_EXCEPTIONS ${yatbcppExceptionsHeadersList}
        src/exceptions/essential_key_missing.cc
        src/exceptions/file_not_found.cc
        src/exceptions/telegram_api_error.cc
        src/exceptions/curl_error.cc
        )

set(SOURCE_FILES_TYPES ${yatbcppTypesHeadersList}
        src/types/Audio.cc
        src/types/Chat.cc
        src/types/ChatMember.cc
        src/types/ChatPhoto.cc
        src/types/Contact.cc
        src/types/Document.cc
        src/types/KeyboardButton.cc
        src/types/File.cc
        src/types/ForceReply.cc
        src/types/Location.cc
        src/types/Message.cc
        src/types/MessageEntity.cc
        src/types/PhotoSize.cc
        src/types/ReplyKeyboardMarkup.cc
        src/types/ReplyKeyboardRemove.cc
        src/types/Update.cc
        src/types/User.cc
        src/types/UserProfilePhotos.cc
        src/types/Venue.cc
        src/types/Video.cc
        src/types/VideoNote.cc
        src/types/Voice.cc

        )

set(SOURCE_FILE_TYPES_FROMJSON
        src/types_fromJson/Audio_fromJson.cc
        src/types_fromJson/Chat_fromJson.cc
        src/types_fromJson/ChatMember_fromJson.cc
        src/types_fromJson/ChatPhoto_fromJson.cc
        src/types_fromJson/Contact_fromJson.cc
        src/types_fromJson/Document_fromJson.cc
        src/types_fromJson/File_fromJson.cc
        src/types_fromJson/KeyboardButton_fromJson.cc
        src/types_fromJson/Location_fromJson.cc
        src/types_fromJson/Message_fromJson.cc
        src/types_fromJson/MessageEntity_fromJson.cc
        src/types_fromJson/PhotoSize_fromJson.cc
        src/types_fromJson/ReplyKeyboardMarkup_fromJson.cc
        src/types_fromJson/Update_fromJson.cc
        src/types_fromJson/User_fromJson.cc
        src/types_fromJson/UserProfilePhotos_fromJson.cc
        src/types_fromJson/Venue_fromJson.cc
        src/types_fromJson/Video_fromJson.cc
        src/types_fromJson/VideoNote_fromJson.cc
        src/types_fromJson/Voice_fromJson.cc
)

set(SOURCE_FILES_METHODS ${yatbcppMethodsHeadersList}
        src/methods/getMe.cc
        src/methods/sendMessage.cc
        )

set(SOURCE_FILES_BOT ${yatbcppBotHeadersList}
        src/bot/Token.cc
        src/bot/Bot.cc
        )

set(SOURCE_FILES
        ${SOURCE_FILES_BOT}
        ${SOURCE_FILES_TYPES}
        ${SOURCE_FILE_TYPES_FROMJSON}
        ${SOURCE_FILES_METHODS}
        ${SOURCE_FILES_EXCEPTIONS}
        ${SOURCE_FILES_OSTREAM_OPERATOR}
        )

########################################################################################################################
# Telegram Bot Library                                                                                                 #
########################################################################################################################

include_directories(inc)
add_library(yatbcpp ${SOURCE_FILES})

set(ConfigPackageLocation lib/cmake/yatbcpp)
########################################################################################################################
# Install Taget                                                                                                        #
########################################################################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/install.cmake)

########################################################################################################################
# Packaging Stuff                                                                                                      #
########################################################################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/findpackage.cmake)

########################################################################################################################
# Documentation Stuff                                                                                                  #
########################################################################################################################
