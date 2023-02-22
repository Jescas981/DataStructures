# Libraries
add_library(array_list INTERFACE
    include/adt/array_list.hpp
    include/adt/array_list.ipp
)

target_include_directories(array_list INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Executables

# Testing
add_executable(array_list_test EXCLUDE_FROM_ALL test/array_list.cpp)
target_link_libraries(array_list_test PRIVATE array_list GTest::gtest GTest::gtest_main)

# Install header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)