

# Add source to this project's executable.
add_executable (pdm_ui
    pdm.cpp
    pdm.h
    main.cpp
    pdm_helpers.hpp
    pdm_themes.hpp
    pdm_databse.cpp pdm_database.h
    lib/sqlite/sqlite3.c # sqlite
    )
target_include_directories(pdm_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    lib/sqlite/ # sqlite
    )
target_link_libraries(pdm_ui ${LIBRARIES} imgui_pdm )
target_compile_definitions(pdm_ui PUBLIC -DImTextureID=ImU64)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pdm_ui PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
