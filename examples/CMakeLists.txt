
file(GLOB children *)

find_path(NOISE_INCLUDE_DIR noise/noise.h)
include_directories(${NOISE_INCLUDE_DIR})
message(STATUS "NOISE_INCLUDE_DIR is ${NOISE_INCLUDE_DIR}")

find_library(NOISE_LIBRARY noise)
message(STATUS "NOISE_LIBRARY is ${NOISE_LIBRARY}")

foreach(child ${children})
    if(IS_DIRECTORY ${child})
        if(EXISTS ${child}/CMakeLists.txt)
        message(STATUS "project ${child} added")
        add_subdirectory(${child})
        endif()
    endif()
endforeach()