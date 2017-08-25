#########################################################################################################################
# Config Version File                                                                                                  #
########################################################################################################################
# https://cmake.org/cmake/help/git-master/manual/cmake-packages.7.html#creating-packages

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfigVersion.cmake"
        VERSION ${yatbcpp_VERSION}
        COMPATIBILITY AnyNewerVersion
)
# Maybe SameMajorVersion

########################################################################################################################
# Cmake Target and configure                                                                                           #
########################################################################################################################

export(EXPORT yatbcppTargets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppTargets.cmake"
        NAMESPACE yatbcpp::
        )

configure_file(CMake/yatbcppConfig.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfig.cmake"
        COPYONLY
        )

#configure_package_config_file(
#        CMake/yatbcppConfig.cmake
#        ${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfig.cmake
#        INSTALL_DESTINATION lib/cmake/yatbcpp
#        NO_CHECK_REQUIRED_COMPONENTS_MACRO
#)

########################################################################################################################
# Config Install Settings                                                                                              #
########################################################################################################################