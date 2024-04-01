cmake_minimum_required(VERSION 3.22)

## Set C and C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

set(PROJECT_NAME example_test)
project(${PROJECT_NAME} LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_compile_definitions(USE_HAL_DRIVER STM32C011xx)

add_subdirectory(Lib)

set(CMAKE_BUILD_TYPE "DEBUG" CACHE STRING "Choose the type of build." FORCE)

enable_testing()
add_subdirectory(Test)
