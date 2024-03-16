project(Graphics)

set(COMMON_INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/Core/include
        include
)

add_subdirectory(SDL2)
add_subdirectory(NCurses)
add_subdirectory(SFML)
