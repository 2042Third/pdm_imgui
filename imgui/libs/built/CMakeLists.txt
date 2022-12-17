#add_library(freetype)
find_library(FREETYPE_LIB freetype ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/freetype/)
#target_link_libraries(freetype ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/freetype/libfreetype.a
#    )
#target_include_directories( freetype  PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/include/freetype
#    )
set( FREETYPE_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/include
    ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/include/freetype
    )
#add_library(harfbuzz  ${CMAKE_CURRENT_SOURCE_DIR}/harfbuzz-icu-freetype/libharfbuzz.a)
#
#
#set_target_properties(harfbuzz PROPERTIES CXX_STANDARD 11)
#set_target_properties(freetype PROPERTIES LINKER_LANGUAGE CXX)
#set_target_properties(harfbuzz PROPERTIES LINKER_LANGUAGE CXX)
