get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB src *.cpp)

add_executable(${TARGET} ${src})
