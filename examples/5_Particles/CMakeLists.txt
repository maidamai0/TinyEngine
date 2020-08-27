get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB src *.cpp)

add_compile_definitions(ROOT="${CMAKE_CURRENT_SOURCE_DIR}/")

add_executable(${TARGET} ${src})
