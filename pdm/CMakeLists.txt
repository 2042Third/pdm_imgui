
# Add source to this project's executable.
add_executable (pdm_ui
    pdm.cpp
    pdm.h
    main.cpp
    handler/pdm_helpers.hpp
    themes/pdm_themes.hpp
    handler/pdm_databse.cpp
    handler/pdm_database.h
#    lib/sqlite/sqlite3.c # sqlite
    handler/pdm_status.h
    ui/pdm_components.hpp
    pdm_ui_control.hpp
    crypto/pdmCryptoDB.hpp # encrypted database
    handler/pdm_net.cpp
    handler/pdm_net.h
    ui/pdm_debug_comps.hpp
    handler/pdm_net_type.cpp
    handler/net_convert.cpp
    handler/types.h
    ui/imgui_custom_ui.cpp
    themes/pdm_colors.h)

find_library(SECUREMEM_LIB SecureMemory ${CMAKE_CURRENT_SOURCE_DIR}/lib/cryptoSQLite/external/securememorybin/bin)

target_include_directories(pdm_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    lib/
    lib/pdm-crypt-module
    lib/pdm-crypt-module/src/lib
    lib/cryptoSQLite
    lib/pdm_network
    lib/json/single_include # json parser
    )


add_subdirectory(lib/pdm-crypt-module) # pdm encryption
add_subdirectory(lib/pdm_network) # pdm network connectivity
add_subdirectory(lib/nativefiledialog-extended) # open dialog
add_subdirectory(lib/cryptoSQLite) # encrypted database

install(FILES PDM_CURL_LOCATION DESTINATION ${PROJECT_BINARY_DIR} )

target_link_libraries(pdm_ui ${LIBRARIES}
    imgui_pdm
    nfd # native file dialog
    cc20 # pdm encryption
    pdm-network # pdm network connectivity
    cryptosqlite # encrypted database interface
    )
target_compile_definitions(pdm_ui PUBLIC -DImTextureID=ImU64)


# TODO: Add tests and install targets if needed.
