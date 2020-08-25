
file(GLOB children *)

foreach(child ${children})
    if(IS_DIRECTORY ${child})
        if(EXISTS ${child}/CMakeLists.txt)
        message(STATUS "project ${child} added")
        add_subdirectory(${child})
        endif()
    endif()
endforeach()