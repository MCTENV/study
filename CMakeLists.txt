cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(Tutorial LANGUAGES CXX)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "use Clang")
    set(CMAKE_AR        "llvm-ar")
    set(CMAKE_LINKER    "llvm-ld")
    set(CMAKE_NM        "llvm-nm")
    set(CMAKE_OBJDUMP   "llvm-objdump")
    set(CMAKE_RANLIB    "llvm-ranlib")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -glldb") 
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOLUTION_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(COMPILER_OUTPUT_PATH ${SOLUTION_PATH}/build)

# set(LIBS_OUTPUT_PATH $ENV{HOME}/lib)
# set(EXEC_OUTPUT_PATH $ENV{HOME}/bin)
set(LIBS_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs)
set(EXEC_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${EXEC_OUTPUT_PATH})
set(LIBRARY_OUTPUT_PATH ${LIBS_OUTPUT_PATH})

# version
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 1)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build/share/tutorial)

configure_file(config/TutorialConfig.h.in config/TutorialConfig.h)

set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_definitions(-DPROJECT_PATH="${PROJECT_SOURCE_DIR}")

message(STATUS "PATH is: $ENV{PATH}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(PCRE REQUIRED)

include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

include_directories(/usr/lib/llvm-12/include/c++/v1/iostream)

option(USE_MYMATH "Use my_math provided math implementation" FALSE)

if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

add_subdirectory(src)

install(FILES "${PROJECT_BINARY_DIR}/config/TutorialConfig.h" DESTINATION include)

include(CTest)
set(CTEST_PROJECT_NAME "CMakeTutorial")
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")
set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)

add_test(NAME Runs COMMAND Tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction(do_test)

# do a bunch of result based tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
