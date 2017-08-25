########################################################################################################################
# Install Target                                                                                                        #
########################################################################################################################
include(GenerateExportHeader)
generate_export_header(yatbcpp)
set_property(TARGET yatbcpp PROPERTY VERSION ${yatbcpp_VERSION})
set_property(TARGET yatbcpp PROPERTY SOVERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp PROPERTY INTERFACE_yatbcpp_MAJOR_VERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp APPEND PROPERTY COMPATIBLE_INTERFACE_STRING yatbcpp_MAJOR_VERSION)


install(TARGETS yatbcpp EXPORT yatbcppTargets
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
        ${yatbcppHeadersList}
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp_export.h"
        DESTINATION
        include/yatbcpp
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