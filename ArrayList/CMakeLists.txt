cmake_minimum_required(VERSION 3.15)
project(ArrayList)

add_library(array_list INTERFACE
    "include/adt/array_list.hpp"
    "include/adt/array_list.ipp"
)

target_include_directories(array_list INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

enable_testing()
add_subdirectory(test)