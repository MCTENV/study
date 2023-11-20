add_executable(llvm-map llvm-map.cpp)
target_compile_options(llvm-map
    PUBLIC -stdlib=libc++
    PUBLIC -std=c++11)

target_link_libraries(llvm-map
    -stdlib=libc++
)