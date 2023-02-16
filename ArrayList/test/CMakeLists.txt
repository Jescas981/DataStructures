include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.0
)
FetchContent_MakeAvailable(googletest)

add_executable(array_list_test "array_list.cpp")
add_test(array_list_test array_list_test)
target_link_libraries(array_list_test PRIVATE array_list GTest::gtest GTest::gtest_main)