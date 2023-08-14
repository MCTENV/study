aux_source_directory(Widget WIDGET)

add_executable(tutorial tutorial.cxx)
target_include_directories(tutorial PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/MathFunctions/include
)
target_compile_definitions(tutorial PUBLIC MY_MACRO=233)
target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

add_executable(main main.cpp ${WIDGET})
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(mytest mytest.cpp)
set_target_properties(mytest PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED True)

add_executable(objects objects.cpp)

add_executable(operators operators.cpp)
target_link_libraries(operators PRIVATE complex)
target_include_directories(operators
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Complex)

add_subdirectory(Net)
add_subdirectory(Others)
add_subdirectory(STL)
add_subdirectory(pThread)
add_subdirectory(Complex)

install(TARGETS tutorial DESTINATION bin)