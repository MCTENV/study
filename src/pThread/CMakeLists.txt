cmake_minimum_required(VERSION 3.5)
project(threads)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(create_thread create.cpp)

target_link_libraries(create_thread pthread)