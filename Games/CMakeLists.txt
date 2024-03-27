project(Games)

set(COMMON_INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/Core/include
        include
)

add_subdirectory(Nibbler)
add_subdirectory(Snake)
