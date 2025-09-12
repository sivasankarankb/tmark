cmake_minimum_required(VERSION 3.10)
project(tmark)
find_package(Catch2 3 REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -fprofile-arcs -ftest-coverage -fpath-coverage -g -O0")
add_executable(tmark_tests mdparser.cpp tests/test_mdparser.cpp)
target_include_directories(tmark_tests PRIVATE .)
target_link_libraries(tmark_tests PRIVATE Catch2::Catch2WithMain)
