cmake_minimum_required(VERSION 3.14)

#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

project(sequence VERSION 0.1
                 DESCRIPTION "Iterators with operator bool() const"
				 LANGUAGES CXX
				 HOMEPAGE_URL https://github.com/keithalewis/epsilon)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(CTest)
include(GNUInstallDirs)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

#add_library(${PROJECT_NAME} INTERFACE)
# add alias so the project can be uses with add_subdirectory
#add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

add_subdirectory(src)

