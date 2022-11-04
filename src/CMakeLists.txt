aux_source_directory(Widget WIDGET)

add_executable(tutorial tutorial.cxx)
add_executable(main main.cpp ${WIDGET})
add_executable(mytest mytest.cpp)

target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(tutorial PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(Net)
add_subdirectory(Others)
add_subdirectory(STL)
add_subdirectory(pThread)
add_subdirectory(Complex)

add_executable(operators operators.cpp)
target_link_libraries(operators PRIVATE complex)
target_include_directories(operators
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Complex)
