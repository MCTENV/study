aux_source_directory(Widget WIDGET)

add_executable(tutorial tutorial.cxx)
add_executable(main main.cpp ${WIDGET})

target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(tutorial PUBLIC
    ${PROJECT_BINARY_DIR}
)

add_subdirectory(Net)
add_subdirectory(Others)
add_subdirectory(STL)