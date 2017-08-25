########################################################################################################################
# Verifying Additional Library Requirments which should be there for linking later on                                  #
########################################################################################################################

########################################################################################################################
# LibCurl for Obtaining the Json Objects                                                                               #
########################################################################################################################
find_package(CURL REQUIRED)
if(CURL_FOUND)
    message(STATUS "CURL found")
    message(STATUS "CURL Include DIR" ${CURL_INCLUDE_DIRS})
    include_directories( ${CURL_INCLUDE_DIRS})
endif()


########################################################################################################################
# LibJsonCPP for Parsing JsonObjects                                                                                   #
########################################################################################################################
find_package(jsoncpp REQUIRED)
if(jsoncpp_FOUND)
    message(STATUS "jsoncpp found")
#    message(STATUS "jsoncpp Include DIR" ${jsoncpp_INCLUDE_DIR})
#    include_directories( ${JSONCPP_INCLUDE_DIR})
endif()