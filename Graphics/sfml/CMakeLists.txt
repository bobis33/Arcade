project(arcade-sfml)

set(INCLUDE_DIR include)

add_library(
        arcade-sfml SHARED
        src/entryPoint.cpp
        src/Sfml.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade-sfml PRIVATE ${INCLUDE_DIR})
target_compile_options(arcade-sfml PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade-sfml PRIVATE arcade-abstractions sfml-graphics sfml-window)
set_property(TARGET arcade-sfml PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade-sfml PROPERTY CXX_STANDARD_REQUIRED ON)
