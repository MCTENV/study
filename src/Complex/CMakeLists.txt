add_library(complex SHARED complex.cc)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)

target_include_directories(complex INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
