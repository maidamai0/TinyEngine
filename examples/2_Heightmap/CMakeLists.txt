get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB src *.cpp)

find_path(NOISE_INCLUDE_DIR noise/noise.h)
include_directories(${NOISE_INCLUDE_DIR})
message(STATUS "NOISE_INCLUDE_DIR is ${NOISE_INCLUDE_DIR}")

find_library(NOISE_LIBRARY noise)
message(STATUS "NOISE_LIBRARY is ${NOISE_LIBRARY}")

add_compile_definitions(ROOT="${CMAKE_CURRENT_SOURCE_DIR}/")

add_executable(${TARGET} ${src})
target_link_libraries(${TARGET} PRIVATE ${NOISE_LIBRARY})
