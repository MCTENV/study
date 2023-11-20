
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
add_executable(rbtree rbtree.cpp)
target_link_libraries(rbtree PUBLIC GTest::gtest)