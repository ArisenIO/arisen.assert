cmake_minimum_required( VERSION 3.5 )

set(ARISEN_VERSION_MIN "1.7")
set(ARISEN_VERSION_SOFT_MAX "1.7")
#set(ARISEN_VERSION_HARD_MAX "")

find_package(arisen)

### Check the version of arisen
set(VERSION_MATCH_ERROR_MSG "")
ARISEN_CHECK_VERSION(VERSION_OUTPUT "${ARISEN_VERSION}"
                                   "${ARISEN_VERSION_MIN}"
                                   "${ARISEN_VERSION_SOFT_MAX}"
                                   "${ARISEN_VERSION_HARD_MAX}"
                                   VERSION_MATCH_ERROR_MSG)
if(VERSION_OUTPUT STREQUAL "MATCH")
   message(STATUS "Using arisen version ${ARISEN_VERSION}")
elseif(VERSION_OUTPUT STREQUAL "WARN")
   message(WARNING "Using arisen version ${ARISEN_VERSION} even though it exceeds the maximum supported version of ${ARISEN_VERSION_SOFT_MAX}; continuing with configuration, however build may fail.\nIt is recommended to use arisen version ${ARISEN_VERSION_SOFT_MAX}.x")
else() # INVALID OR MISMATCH
   message(FATAL_ERROR "Found arisen version ${ARISEN_VERSION} but it does not satisfy version requirements: ${VERSION_MATCH_ERROR_MSG}\nPlease use arisen version ${ARISEN_VERSION_SOFT_MAX}.x")
endif(VERSION_OUTPUT STREQUAL "MATCH")


enable_testing()

configure_file(${CMAKE_SOURCE_DIR}/contracts.hpp.in ${CMAKE_BINARY_DIR}/contracts.hpp)

include_directories(${CMAKE_BINARY_DIR})

file(GLOB UNIT_TESTS "*.cpp" "*.hpp")

add_arisen_test( unit_test ${UNIT_TESTS} )

target_compile_options(unit_test PUBLIC -DASSERT_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")
