cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(sequence VERSION 0.1
                 DESCRIPTION "Iterators with operator bool() const"
				 LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
	include(CTest)
endif()

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

add_subdirectory(src)

