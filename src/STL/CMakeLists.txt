add_executable(stl_algo stl_algorithm.cpp)
add_executable(stl_adapter stl_adapter.cpp)

target_link_libraries(stl_algo -fsanitize=address)
target_link_libraries(stl_adapter)