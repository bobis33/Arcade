project(arcade_sdl2)

add_library(arcade_sdl2 SHARED
        src/entryPoint.cpp
        src/Sdl2.cpp
        src/Events.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMMON_WARNING_FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE arcade_abstractions SDL2)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

