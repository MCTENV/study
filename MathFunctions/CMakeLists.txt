cmake_minimum_required(VERSION 3.6)
project(Math)

set(Math_VERSION_MAJOR 1)
set(Math_VERSION_NOJAR 0)

include_directories(include)
configure_file(config/MathFunctionsConfig.h config/MathFunctionsConfig.h.in)

add_executable(MakeTable src/make_table.cxx)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${PROJECT_SOURCE_DIR}/include/Table.h
    DEPENDS MakeTable
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(MathFunctions
    src/mysqrt.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)
# 使用requirements来控制链接库
# 首先声明任何链接MathFunctions的project需要包含当前源目录
# 使用INTERFACE表明提供者不需要链接，而使用者需要链接
# 添加以后就可以移除使用者的
# EXTRA_INCLUDES选项
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
          PRIVATE ${CMAKE_BINARY_DIR}/config
)

# 这是个库，不应该装在bin中
install(TARGETS MathFunctions DESTINATION lib)
install(FILES include/my_math.h DESTINATION include)
