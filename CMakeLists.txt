cmake_minimum_required(VERSION 3.16)
project(OOP_LAB5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Общие include-директории ===
include_directories(
    ${CMAKE_SOURCE_DIR}
)

# === Основное приложение ===
add_executable(OOP_LAB5
    main.cpp
)

# === GoogleTest ===
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(OOP_LAB5_tests
    tests/test_forward_list.cpp
)

target_link_libraries(OOP_LAB5_tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(OOP_LAB5_tests)
