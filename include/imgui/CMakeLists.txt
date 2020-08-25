get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(imgui_src
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_widgets.cpp
    imgui_impl_opengl3.cpp
    imgui_impl_sdl.cpp
)

add_library(${TARGET} ${imgui_src})
