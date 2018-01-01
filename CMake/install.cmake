########################################################################################################################
# Install Target                                                                                                        #
########################################################################################################################
include(GenerateExportHeader)
#generate_export_header(yatbcpp_static)
#generate_export_header(yatbcpp_shared)
set_property(TARGET yatbcpp_static PROPERTY VERSION ${yatbcpp_VERSION})
set_property(TARGET yatbcpp_shared PROPERTY VERSION ${yatbcpp_VERSION})
set_property(TARGET yatbcpp_static PROPERTY SOVERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp_shared PROPERTY SOVERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp_static PROPERTY INTERFACE_yatbcpp_MAJOR_VERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp_shared PROPERTY INTERFACE_yatbcpp_MAJOR_VERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp_static APPEND PROPERTY COMPATIBLE_INTERFACE_STRING yatbcpp_MAJOR_VERSION)
set_property(TARGET yatbcpp_shared APPEND PROPERTY COMPATIBLE_INTERFACE_STRING yatbcpp_MAJOR_VERSION)


install(TARGETS yatbcpp_shared EXPORT yatbcppTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)
install(TARGETS yatbcpp_static EXPORT yatbcppTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)

########################################################################################################################
# Main Headers from root and main include header                                                                       #
########################################################################################################################

install(
        FILES
        yatbcpp.h
        #"${CMAKE_CURRENT_BINARY_DIR}/yatbcpp_export.h"
        DESTINATION
        include/yatbcpp
        COMPONENT
        Devel
)

########################################################################################################################
# Bot Headers                                                                                                          #
########################################################################################################################

install(
        FILES
        ${yatbcppBotHeadersList}
        DESTINATION
        include/yatbcpp/bot/
        COMPONENT
        Devel
)

########################################################################################################################
# Type Headers                                                                                                         #
########################################################################################################################

install(
        FILES
        ${yatbcppTypesHeadersList}
        DESTINATION
        include/yatbcpp/types/
        COMPONENT
        Devel
)

########################################################################################################################
# Telegram Function  Headers                                                                                           #
########################################################################################################################

install(
        FILES
        ${yatbcppMethodsHeadersList}
        DESTINATION
        include/yatbcpp/methods/
        COMPONENT
        Devel
)

########################################################################################################################
# Exception Headers                                                                                                    #
########################################################################################################################

install(
        FILES
        ${yatbcppExceptionsHeadersList}
        DESTINATION
        include/yatbcpp/exceptions/
        COMPONENT
        Devel
)



install(EXPORT yatbcppTargets
        FILE
#        yatbcpp.cmake
        yatbcppTargets.cmake
        NAMESPACE
        yatbcpp::
        DESTINATION
        ${ConfigPackageLocation}
        )

install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfigVersion.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppTargets.cmake"
        DESTINATION
        ${ConfigPackageLocation}
        COMPONENT
        Devel
)
