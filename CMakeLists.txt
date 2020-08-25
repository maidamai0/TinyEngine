cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(Boost COMPONENTS filesystem REQUIRED )

link_libraries(GLEW::GLEW glm  SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_image SDL2::SDL2_mixer SDL2::SDL2_ttf Boost::filesystem)

add_subdirectory(include)

link_libraries(imgui)
add_subdirectory(examples)