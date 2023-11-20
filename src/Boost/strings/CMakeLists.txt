add_executable(strings-locale locale.cpp)

set_target_properties(strings-locale PROPERTIES CMAKE_CXX_LINKER_LAUNCHER CXX_LINKER_LAUNCHER)

find_package(Boost REQUIRED COMPONENTS
    regex
)

add_executable(strings-algorithm algorithm.cpp)
target_link_libraries(strings-algorithm PRIVATE Boost::regex)

add_executable(strings-regex regex.cpp)
target_link_libraries(strings-regex PRIVATE Boost::regex)


add_executable(strings-tokenizer tokenizer.cpp)

add_executable(strings-format format.cpp)