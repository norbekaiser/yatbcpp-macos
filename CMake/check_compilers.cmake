########################################################################################################################
# Verifying Compiler Compability                                                                                       #
########################################################################################################################
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++1z" COMPILER_SUPPORTS_CXX1Z)

########################################################################################################################
# Verifying Compiler Compability C++17                                                                                 #
########################################################################################################################
if(COMPILER_SUPPORTS_CXX17)
    set(CMAKE_CXX_FLAGS "-std=c++17")
    message(STATUS "The Compiler ${CMAKE_CXX_COMPILER} has C++17 support. It is now enabled.")
elseif(COMPILER_SUPPORTS_CXX1Z)
    set(CMAKE_CXX_FLAGS "-std=c++1z")
    message(STATUS "The Compiler ${CMAKE_CXX_COMPILER} has experimental C++17 support. It is now enabled.")
else()
    message(FATAL_ERROR "The Compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ Compiler")
endif()
