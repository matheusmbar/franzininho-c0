cmake_minimum_required(VERSION 3.22)

add_subdirectory(cpputest)
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")

set(TEST_NAME run_tests)

add_executable(${TEST_NAME}
    src/main.cpp
    src/test1.cpp
    src/device/ut_gpio_pin.cpp
    src/device/ut_led.cpp
    src/mock/mock_hal_gpio.c

    )

target_include_directories(${TEST_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${TEST_NAME} PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt
    project_lib
    )

include(CTest)

add_test(${TEST_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME} )
