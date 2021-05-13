cmake_minimum_required(VERSION 3.10)
project (Tutorial)
# version
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 1)

# 指定c++11版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. 设置安装目录
set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build/share/tutorial)

# 配置一个头文件，向源码传递一些cmake设置
configure_file(config/TutorialConfig.h.in config/TutorialConfig.h)
# configure_file(
#     ${PROJECT_SOURCE_DIR}/TutorialConfig.h.in
#     ${PROJECT_BINARY_DIR}/TutorialConfig.h
# )

set (CMAKE_C_FLAGS "libpcrecpp")
list (APPEND EXTRA_LIBS pcrecpp)

# 添加config.h文件目录
# 改为target_link_directories，为什么？
# include_directories("${PROJECT_BINARY_DIR}")

# 2. 添加可选第三方库，问：宏定义为什么不生效？
# 生效：1. cmake -DUSE_MYMATH=ON ..
#      2. 删掉build之后再重新构建，ON不生效，version改为3.10可以
# 这个宏定义是通过config.h.in文件传递给源代码的
# 在config.h.in中添加#cmakedefine USE_MYMATH
option(USE_MYMATH "Use my_math provided math implementation" ON)

# 2. 添加第三方库
if(USE_MYMATH)
    # 添加第三方库math，需注意，添加的是包含头文件的目录
    # 现在改为加入target_link_directories指令中，更好控制libs和incs这两行，只针对某个target去链接
    # include_directories(${PROJECT_SOURCE_DIR}/MathFunctions/include)
    # 添加编译目录，同时构建
    add_subdirectory(MathFunctions)
    # 疑问:为什么指定MathFunctions？能起别名吗？命名规则是怎样的
    # set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    # The variable EXTRA_INCLUDES is used similarly for optional header files
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions/include")
endif()

add_executable(tutorial src/tutorial.cxx)
# 链接使用第三方库
target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})
# Since the configured file will be written into the binary tree,
# we must add that directory to the list of paths to search for include files
# 由于config文件将被写入binary tree，必须将包含config的目录加入搜索路径中
target_include_directories(tutorial PUBLIC
    ${PROJECT_BINARY_DIR}
    # ${EXTRA_INCLUDES} # 链接目标cmakelist中必须有target_include_directories interface
)

# 3. 安装
install (TARGETS tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config/TutorialConfig.h" DESTINATION include)

# 测试
enable_testing()
# 测试是否运行
add_test(tutorial_run tutorial 25)

# 测试是否正确
add_test(tutorial_cal tutorial 25)
# 测试通过输出表达式
set_tests_properties(tutorial_cal
    PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5"
)
# # 测试异常情况
# add_test(tutorial_exp tutorial -25)
# set_tests_properties(tutorial_exp
#     PROPERTIES PASS_REGULAR_EXPRESSION "-25 is [-nan|nan|0]"
# )

# # 测试小数
# add_test(tutorial_min tutorial 0.0001)
# set_tests_properties(tutorial_min
#     PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01"
# )

# # 非数字
# add_test(tutorial_nnu tutorial )
# set_tests_properties(tutorial_nnu
#     PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .*number"
# )
function(do_test target arg result)
add_test(NAME Comp${arg} COMMAND ${target} ${arg})    
set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
)
endfunction(do_test target arg result)

do_test(tutorial 4 "4 is 2")
do_test(tutorial 9 "9 is 3")
do_test(tutorial 5 "5 is 2.236")
do_test(tutorial 7 "7 is 2.645")
do_test(tutorial 25 "25 is 5")
do_test(tutorial -25 "-25 is [-nan|nan|0]")
do_test(tutorial 0.0001 "0.0001 is 0.01")