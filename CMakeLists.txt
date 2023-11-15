cmake_minimum_required(VERSION 3.26)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp)

include_directories(Task1)
add_subdirectory(Task1)

target_link_libraries(Lab2 Task1)

add_subdirectory(Google_tests)