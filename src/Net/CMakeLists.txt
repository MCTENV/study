cmake_minimum_required(VERSION 3.10)

project(my-net LANGUAGES CXX)

find_package(Poco COMPONENTS Net Util Foundation)

add_executable(server poco-server.cpp)
target_link_libraries(server Poco::Net Poco::Util Poco::Foundation)

add_executable(client poco-client.cpp)
target_link_libraries(client Poco::Net Poco::Util Poco::Foundation)

