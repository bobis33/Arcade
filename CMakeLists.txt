cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Release)

option(USE_CLANG_TIDY "Use Clang-tidy" OFF)

project(arcade
        VERSION 0.1.0
        DESCRIPTION "EPITECH | B-OOP-400 | Arcade"
        LANGUAGES CXX
)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Core/src/)

set(WARNING_FLAGS
        -Wall
        -Wextra
        -Werror
        -Wdeprecated-copy
        -Wmisleading-indentation
        -Wnull-dereference
        -Woverloaded-virtual
        -Wpedantic
        -Wshadow
        -Wsign-conversion
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

# Build Doxygen documentation
include(cmake/MakeDoc.cmake)

# Clang format
if (USE_CLANG_TIDY)
    include(cmake/ClangTidy.cmake)
endif()

# Set output directories
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Add subdirectories
add_subdirectory(Graphics)
add_subdirectory(Games)

# Interface library
add_library(arcade_abstractions INTERFACE)

add_executable(${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/Core/init.cpp
        ${SRC_DIR}/Core/Core.cpp
        ${SRC_DIR}/Core/Events.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Core/include/)

# Set compile and link options
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_link_options(${PROJECT_NAME} PRIVATE -rdynamic)

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
