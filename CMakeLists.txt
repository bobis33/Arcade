cmake_minimum_required(VERSION 3.22)

project(arcade)

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

#Set sources
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/Core.cpp
)

# Set output directories
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Add include directories
include_directories(${INCLUDE_DIR})

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
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS} ${GCC_WARNING_FLAGS})
target_link_options(arcade PRIVATE -rdynamic)

# Set properties
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
