cmake_minimum_required(VERSION 3.14)

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

