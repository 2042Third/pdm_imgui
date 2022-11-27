

# Add source to this project's executable.
add_executable (pdm_ui
    pdm.cpp
    pdm.h
    main.cpp
    pdm_helpers.hpp
    pdm_themes.hpp
    pdm_databse.cpp pdm_database.h
    lib/sqlite/sqlite3.c # sqlite
    pdm_status.h
    pdm_components.hpp
    pdm_ui_control.hpp

    )
target_include_directories(pdm_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    lib/sqlite/ # sqlite
    )


add_subdirectory(lib/nativefiledialog-extended)

target_link_libraries(pdm_ui ${LIBRARIES} imgui_pdm nfd)
target_compile_definitions(pdm_ui PUBLIC -DImTextureID=ImU64)


# TODO: Add tests and install targets if needed.
