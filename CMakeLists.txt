cmake_minimum_required(VERSION 3.21.1)

project(improvCPP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set a CMake variable for the jsoncpp include and library directories
set(JSONCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/jsoncpp/include)
set(JSONCPP_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/jsoncpp/build/lib)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(src)

# Copy the configuration folder to the build directory
file(COPY config DESTINATION ${CMAKE_BINARY_DIR})

# Set a variable indicating whether to copy resources
option(COPY_RESOURCES "Copy the resources folder" OFF)

# If COPY_RESOURCES is ON, copy the resources folder to the build directory
if(COPY_RESOURCES)
    file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})
    message(STATUS "Copying resources folder to build directory.")
else()
    message(STATUS "Not copying resources folder.")
endif()
