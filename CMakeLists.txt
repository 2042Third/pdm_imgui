# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (pdm_platforms_ui C CXX)


set(CMAKE_CXX_STANDARD 17)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

# GLFW
set(GLFW_DIR ./glfw) # Set this to point to an up-to-date GLFW repo
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)
include_directories(${GLFW_DIR}/include)


# Dear ImGui
set(IMGUI_DIR ./imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)

# Libraries
find_package(Vulkan REQUIRED)
#find_library(VULKAN_LIBRARY
  #NAMES vulkan vulkan-1)
#set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
set(LIBRARIES "glfw;Vulkan::Vulkan")

# Use vulkan headers from glfw:
include_directories(${GLFW_DIR}/deps)

# PDM
set(PDM_DIR ./pdm)
file(GLOB sources *.cpp)

# Freetype
#find_package(Freetype)
#set (SKIP_INSTALL_ALL ON)
#add_subdirectory(${IMGUI_DIR}/libs/freetype ${CMAKE_BINARY_DIR}/freetype)
#target_link_libraries(imgui-freetype INTERFACE freetype)
#target_compile_definitions(imgui-freetype INTERFACE -DIMGUI_ENABLE_FREETYPE=1)
add_subdirectory(${IMGUI_DIR}/libs/harfbuzz-icu-freetype)

# Include sub-projects.
add_executable(pdm_ui ${sources}
    ${PDM_DIR}/main.cpp
    ${PDM_DIR}/pdm.cpp
    ${PDM_DIR}/pdm.h
    ${PDM_DIR}/pdm_helpers.hpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/misc/freetype/imgui_freetype.h   # Freetype
    ${IMGUI_DIR}/misc/freetype/imgui_freetype.cpp # Freetype
    ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp pdm/pdm_helpers.hpp)
target_link_libraries(pdm_ui ${LIBRARIES} freetype harfbuzz )
target_compile_definitions(pdm_ui PUBLIC -DImTextureID=ImU64)

