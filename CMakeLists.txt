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
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/files_header.cmake)


########################################################################################################################
# Telegram Bot Source Files                                                                                            #
########################################################################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/files_cxx.cmake)

set(SOURCE_FILES
        ${SOURCE_FILES_BOT}
        ${SOURCE_FILES_TYPES}
        ${SOURCE_FILE_TYPES_FROMJSON}
        ${SOURCE_FILE_TYPES_FROMSTRING}
        ${SOURCE_FILES_METHODS}
        ${SOURCE_FILES_EXCEPTIONS}
        ${SOURCE_FILES_OSTREAM_OPERATOR}
        )

########################################################################################################################
# Telegram Bot Library                                                                                                 #
########################################################################################################################

include_directories(inc)
#https://cmake.org/cmake/help/v3.5/command/add_library.html#object-libraries

add_library(objlib OBJECT ${SOURCE_FILES})
set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)


#add_library(yatbcpp $<TARGET_OBJECTS:objlib>)
add_library(yatbcpp_shared SHARED $<TARGET_OBJECTS:objlib>)
add_library(yatbcpp_static STATIC $<TARGET_OBJECTS:objlib>)
set_target_properties(yatbcpp_shared PROPERTIES OUTPUT_NAME "yatbpcpp")
set_target_properties(yatbcpp_static PROPERTIES OUTPUT_NAME "yatbpcpp")


#add_library(yatbcpp_shared SHARED ${SOURCE_FILES})
#add_library(yatbcpp  STATIC ${SOURCE_FILES})

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
