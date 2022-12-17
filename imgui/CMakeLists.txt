



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
find_library(FREETYPE_LIB freetype ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/freetype/)
target_include_directories(imgui_pdm PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/built/harfbuzz-icu-freetype/include/freetype
    )
target_link_libraries(imgui_pdm ${LIBRARIES}
#    harfbuzz
    ${FREETYPE_LIB}
    )

