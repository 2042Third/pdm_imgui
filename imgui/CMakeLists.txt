



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
# Find and load the built static library for freetype.
find_library(FREETYPE_LIB freetype ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/freetype/)
# Includes of the built static library fir freetype.
target_include_directories(imgui_pdm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/include/freetype
    )
target_link_libraries(imgui_pdm ${LIBRARIES}
    ${FREETYPE_LIB}
    )

