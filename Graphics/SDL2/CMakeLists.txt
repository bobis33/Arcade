project(arcade_sdl2
        VERSION 0.1.0
        DESCRIPTION "SDL2 library for the arcade project"
        LANGUAGES C CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/Sdl2Window.cpp
        ${SRC_DIR}/Event.cpp
        ${SRC_DIR}/Sprite.cpp
        ${SRC_DIR}/Text.cpp
        ${SRC_DIR}/Sound.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE arcade_abstractions SDL2 SDL2_image SDL2_ttf SDL2_mixer)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

