# project(complex)
set(project_name complex)

add_library(${project_name} SHARED complex.cc)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)

target_include_directories(${project_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
