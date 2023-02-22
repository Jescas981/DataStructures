cmake_minimum_required(VERSION 3.15)
project(DSC VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "Data Structure Course - Udemy")

set(CMAKE_CXX_STANDARD 17)

# Testing libraries
enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.0
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(ArrayList)

# Testing command
add_custom_target(check)
add_dependencies(check 
    array_list_test
)

# Configuration file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}-config.cmake.in
    ${PROJECT_NAME}-config.cmake
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(
    ${PROJECT_NAME}-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install headers and libraries
install(
    TARGETS array_list
    EXPORT ${PROJECT_NAME}-targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Export the targets for use by other projects
install(EXPORT ${PROJECT_NAME}-targets   
    DESTINATION lib/cmake/${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}-config.cmake
)