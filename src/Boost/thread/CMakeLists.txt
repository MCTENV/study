
find_package(Boost 1.74.0 COMPONENTS thread)

add_executable(thread-manage manage.cpp)
target_link_libraries(thread-manage Boost::thread)

add_executable(thread-sync sync.cpp)
target_link_libraries(thread-sync Boost::thread)

add_executable(thread-sum sum.cpp)
target_link_libraries(thread-sum Boost::thread)