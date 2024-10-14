# FindPcre.cmake

if (APPLE)
  set(CMAKE_FIND_ROOT_PATH "/opt/homebrew")
  list(APPEND CMAKE_SYSTEM_INCLUDE_PATH "/opt/homebrew/include")
  list(APPEND CMAKE_SYSTEM_LIBRARY_PATH "/opt/homebrew/lib")
  include_directories("/opt/homebrew/include")
  link_directories("/opt/homebrew/lib")
endif (APPLE)

# Find PCRE include directory
find_path(PCRE_INCLUDE_DIR pcrecpp.h
  HINTS
  ${CMAKE_FIND_ROOT_PATH}/include
  $ENV{PCRE_INCLUDE_DIR}
  ~/include
  /usr/include
  /usr/local/include
)

# Find PCRE library
find_library(PCRE_LIBRARY pcrecpp
  HINTS
  ${CMAKE_FIND_ROOT_PATH}/lib
  $ENV{PCRE_LIBRARY}
  ~/lib
  /usr/lib
  /usr/local/lib
)

# Check PCRE version
if(PCRE_INCLUDE_DIR AND PCRE_LIBRARY)
  file(READ ${PCRE_INCLUDE_DIR}/pcrecpp.h PCRE_VERSION_CONTENTS)
  string(REGEX MATCH "define[[:space:]]+PCRE_MAJOR[[:space:]]+([0-9]+)" _ ${PCRE_VERSION_CONTENTS})
  set(PCRE_MAJOR_VERSION ${CMAKE_MATCH_1})
  string(REGEX MATCH "define[[:space:]]+PCRE_MINOR[[:space:]]+([0-9]+)" _ ${PCRE_VERSION_CONTENTS})
  set(PCRE_MINOR_VERSION ${CMAKE_MATCH_1})
  string(REGEX MATCH "define[[:space:]]+PCRE_PRERELEASE[[:space:]]+([0-9]+)" _ ${PCRE_VERSION_CONTENTS})
  set(PCRE_PRERELEASE_VERSION ${CMAKE_MATCH_1})
  set(PCRE_VERSION ${PCRE_MAJOR_VERSION}.${PCRE_MINOR_VERSION}.${PCRE_PRERELEASE_VERSION})
endif()

# Set PCRE_FOUND variable
if(PCRE_INCLUDE_DIR AND PCRE_LIBRARY AND PCRE_VERSION)
  set(PCRE_FOUND TRUE)
else()
  set(PCRE_FOUND FALSE)
endif()

# Handle REQUIRED and QUIET arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PCRE
  FOUND_VAR PCRE_FOUND
  REQUIRED_VARS PCRE_INCLUDE_DIR PCRE_LIBRARY
  VERSION_VAR PCRE_VERSION
)