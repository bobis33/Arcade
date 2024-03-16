cmake_minimum_required(VERSION 3.22)

project(arcade
        VERSION 1.0.0
        LANGUAGES CXX)

# Set C++ standard and build type
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

# Set directories
set(INCLUDE_DIR
        Core/include/
)
set(SRC_DIR
        Core/src/
)

# Set warning flags
set(WARNING_FLAGS
        -Wall
        -Wduplicated-branches
        -Wduplicated-cond
        -Wextra
        -Werror
        -Wdeprecated-copy
        -Wlogical-op
        -Wmisleading-indentation
        -Wnull-dereference
        -Woverloaded-virtual
        -Wpedantic
        -Wshadow
        -Wsign-conversion
        -Wuseless-cast
        -Wnon-virtual-dtor
        -Wunused
        -Wcast-align
        -Wno-padded
        -Wconversion
        -Wformat
        -Winit-self
        -Wmissing-include-dirs
        -Wold-style-cast
        -Wredundant-decls
        -Wswitch-default
        -Wswitch-enum
        -Wundef
)
set(GCC_WARNING_FLAGS
        -Wmisleading-indentation
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wnull-dereference
        -Wuseless-cast
)

set(COMMON_WARNING_FLAGS
        ${WARNING_FLAGS}
        ${GCC_WARNING_FLAGS}
)

#Set sources
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/Core/init.cpp
        ${SRC_DIR}/Core/Core.cpp
        ${SRC_DIR}/Core/Events.cpp
)

# Doxygen
find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH Core/include)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.doxygen)
    set(DOXYGEN_DISABLE_INDEX NO)
    set(DOXYGEN_FULL_SIDEBAR NO)
    set(DOXYGEN_HTML_COLORSTYLE LIGHT)
    doxygen_add_docs(doc
            Core/include
            Graphics/SDL2/include
            Graphics/NCurses/include
            Graphics/SFML/include
            ALL
    )
    add_custom_command(TARGET doc
            POST_BUILD
            WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}/latex
            COMMAND ${CMAKE_MAKE_PROGRAM} > /dev/null
            && ${CMAKE_COMMAND} -E copy
            ${DOXYGEN_OUTPUT_DIRECTORY}/latex/refman.pdf
            ${CMAKE_SOURCE_DIR}/doc/Arcade.pdf
            BYPRODUCTS ${CMAKE_SOURCE_DIR}/doc/Arcade.pdf
            VERBATIM
    )
else ()
    message(WARNING "Doxygen is necessary for docs")
endif ()

# Set output directories
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Add subdirectories
add_subdirectory(Graphics)
add_subdirectory(Games)

# Interface library
add_library(arcade_abstractions INTERFACE)
set_property(TARGET arcade_abstractions PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_abstractions PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Set compile and link options
target_compile_options(${PROJECT_NAME} PRIVATE ${COMMON_WARNING_FLAGS})
target_link_options(arcade PRIVATE -rdynamic)

# Set properties
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
