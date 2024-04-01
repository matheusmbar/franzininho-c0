cmake_minimum_required(VERSION 3.22)

# CppUTest
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master # or use release tag, eg. v4.0
    SOURCE_DIR     "${CMAKE_SOURCE_DIR}/thirdy-party/cpputest"
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

set(TEST_NAME run_tests)

add_executable(${TEST_NAME}
    Src/main.cpp
    Src/ut_basic.cpp
    Src/device/ut_gpio_pin.cpp
    Src/mock/mock_hal_gpio.c
    )

target_include_directories(${TEST_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/Inc
)

target_link_libraries(${TEST_NAME} PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt
    project_lib
    )

include(CTest)
add_test(${TEST_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME} )
