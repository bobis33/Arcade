project(arcade_ncurses)

set(INCLUDE_DIR include)

add_library(
        arcade_ncurses SHARED
        src/entryPoint.cpp
        src/Ncurses.cpp
        src/Events.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_ncurses PRIVATE ${INCLUDE_DIR})
target_compile_options(arcade_ncurses PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_ncurses PRIVATE arcade_abstractions ncurses)
set_property(TARGET arcade_ncurses PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_ncurses PROPERTY CXX_STANDARD_REQUIRED ON)
