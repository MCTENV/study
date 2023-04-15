set(CMAKE_BUILD_TYPE Debug)

add_definitions(-DPROJECT_PATH="${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(stl_algo stl_algorithm.cpp)
add_executable(stl_adapter stl_adapter.cpp)
add_executable(stl_utility stl_utility.cpp)
add_executable(stl_math stl_math.cpp)
add_executable(stl_regex stl_regex.cpp)

target_link_libraries(stl_algo -fsanitize=address)
target_link_libraries(stl_adapter)