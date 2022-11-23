



add_library(imgui_pdm
    backends/imgui_impl_glfw.cpp
    misc/freetype/imgui_freetype.h   # Freetype
    misc/freetype/imgui_freetype.cpp # Freetype
    backends/imgui_impl_vulkan.cpp
    imgui.cpp
    imgui_draw.cpp
    imgui_demo.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    )

target_link_libraries(imgui_pdm ${LIBRARIES} freetype harfbuzz )

