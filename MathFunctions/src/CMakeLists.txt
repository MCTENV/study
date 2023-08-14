add_executable(make_table make_table.cxx)

add_custom_command(
    OUTPUT Table.h
    COMMAND make_table ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND make_table ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/Table.h
    DEPENDS make_table
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(MathFunctions SHARED
    mysqrt.cxx
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

# # 这是个库，不应该装在bin中
install(TARGETS MathFunctions DESTINATION lib)
# install(FILES include/my_math.h DESTINATION include)