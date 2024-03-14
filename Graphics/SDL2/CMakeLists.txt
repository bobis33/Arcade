project(arcade_sdl2)

set(INCLUDE_DIR include)

add_library(
        arcade_sdl2 SHARED
        src/entryPoint.cpp
        src/Sdl2.cpp
        src/Events.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_sdl2 PRIVATE ${INCLUDE_DIR})
target_compile_options(arcade_sdl2 PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_sdl2 PRIVATE arcade_abstractions SDL2)
set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD_REQUIRED ON)
