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
file(GLOB yatbcppHeadersList
        "inc/*.h"
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
        src/types/KeyboardLocation.cc
        src/types/File.cc
        src/types/Location.cc
        src/types/Message.cc
        src/types/MessageEntity.cc
        src/types/PhotoSize.cc
        src/types/Update.cc
        src/types/User.cc
        src/types/UserProfilePhotos.cc
        src/types/Venue.cc
        src/types/Video.cc
        src/types/VideoNote.cc
        src/types/Voice.cc

        src/types/sendMessage.cc
        )

set(SOURCE_FILES
        src/Token.cc inc/Token.h
        src/Bot.cc inc/Bot.h
        ${SOURCE_FILES_TYPES}
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
