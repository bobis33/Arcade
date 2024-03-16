project(arcade_ncurses
        VERSION 0.1.0
        DESCRIPTION "ncurses library for the arcade project"
        LANGUAGES CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

add_library(arcade_ncurses SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        src/entryPoint.cpp
        src/Ncurses.cpp
        src/Events.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE arcade_abstractions ncurses)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)