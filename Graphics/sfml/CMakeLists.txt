project(arcade-sfml)

set(SRC_DIR src)
set(INCLUDE_DIR include)

add_library(
        arcade-sfml SHARED
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/Sfml.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade-sfml PRIVATE ${INCLUDE_DIR})
target_compile_options(arcade-sfml PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade-sfml PRIVATE arcade-abstractions sfml-graphics sfml-window)
set_property(TARGET arcade-sfml PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade-sfml PROPERTY CXX_STANDARD_REQUIRED ON)
