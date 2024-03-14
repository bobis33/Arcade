project(arcade-ncurses)

set(INCLUDE_DIR include)

add_library(
        arcade-ncurses SHARED
        src/entryPoint.cpp
        src/Ncurses.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade-ncurses PRIVATE ${INCLUDE_DIR})
target_compile_options(arcade-ncurses PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade-ncurses PRIVATE arcade-abstractions ncurses)
set_property(TARGET arcade-ncurses PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade-ncurses PROPERTY CXX_STANDARD_REQUIRED ON)
