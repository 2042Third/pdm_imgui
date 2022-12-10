# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.24)
cmake_policy(SET CMP0079 NEW) # allow things from other directories
cmake_policy(SET CMP0135 NEW) # cryptoSqlite icu download prebuilt binary
project (pdm_platforms_ui C CXX)

set(CMAKE_CXX_STANDARD 20)
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
add_subdirectory(${IMGUI_DIR}/libs/harfbuzz-icu-freetype)


# Libraries
find_package(Vulkan REQUIRED)
set(LIBRARIES "glfw;Vulkan::Vulkan")

# Use vulkan headers from glfw:
include_directories(${GLFW_DIR}/deps)


# PDM
set(PDM_DIR ./pdm)
add_subdirectory(imgui)
add_subdirectory(pdm)

