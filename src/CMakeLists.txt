cmake_minimum_required(VERSION 3.10)
project(tmark)
find_package(Catch2 3 REQUIRED)

string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)

if (build_type STREQUAL debug)
  set(CMAKE_CXX_FLAGS "-Wall -fprofile-arcs -ftest-coverage -fpath-coverage -g -O0")

elseif (build_type STREQUAL release)
  set(CMAKE_CXX_FLAGS "-Wall -O3")

endif()

add_executable(tmark_tests mdparser.cpp htmlgen.cpp tests/test_mdparser.cpp tests/test_htmlgen.cpp)
target_include_directories(tmark_tests PRIVATE .)
target_link_libraries(tmark_tests PRIVATE Catch2::Catch2WithMain)
