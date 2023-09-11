find_package(Boost REQUIRED COMPONENTS serialization)

add_executable(test1 test1.cpp)
target_link_libraries(test1 Boost::serialization)