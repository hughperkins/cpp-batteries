cmake_minimum_required(VERSION 2.8)

if (NOT CMAKE_BUILD_TYPE)
    message("Setting build type to 'Release'")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

include_directories(.)

add_library( cpp-batteries SHARED cpp-batteries/StringHelper.cpp cpp-batteries/FileHelper.cpp )

add_library( gtest SHARED thirdparty/gtest/gtest-all.cc )
target_link_libraries( gtest pthread )

add_executable( unittests test/testStringHelper.cpp cpp-batteries/StringHelper.cpp thirdparty/gtest/gtest_main.cc )
target_link_libraries( unittests cpp-batteries gtest )
target_include_directories( unittests PRIVATE thirdparty/gtest )

