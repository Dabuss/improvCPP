cmake_minimum_required(VERSION 3.21.1)

project(improvCPP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set a CMake variable for the jsoncpp include and library directories
set(JSONCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/jsoncpp/include)
set(JSONCPP_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/jsoncpp/build/lib)

find_package(Qt6 REQUIRED COMPONENTS Widgets) 

add_subdirectory(src)