find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH
            Core/include
            Graphics/SDL2/include
            Graphics/NCurses/include
            Graphics/SFML/include
            Games/Nibbler/include
            Games/Snake/include
    )
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.doxygen)
    doxygen_add_docs(doc
            Core/include
            Graphics/SDL2/include
            Graphics/NCurses/include
            Graphics/SFML/include
            Games/Nibbler/include
            Games/Snake/include
            ALL
    )
    add_custom_command(TARGET doc
            POST_BUILD
            WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}/latex
            COMMAND ${CMAKE_MAKE_PROGRAM} > /dev/null
            && ${CMAKE_COMMAND} -E copy
            ${DOXYGEN_OUTPUT_DIRECTORY}/latex/refman.pdf
            ${CMAKE_SOURCE_DIR}/doc/Arcade.pdf
            BYPRODUCTS ${CMAKE_SOURCE_DIR}/doc/Arcade.pdf
            VERBATIM
    )
else ()
    message(WARNING "Doxygen is necessary for docs")
endif ()