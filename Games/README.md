
# Arcade - Games

Explanation for implementing new games

## Description

Here you will find the instructions for adding a new game to the Arcade project, following these steps will then make it simple to get it working. You can find as an example the two games already implemented, Snake and Nibbler.

## Add a new game

First, you will need to create a class that inherits from "Agame", and implement the following methods :

- loadGame
- gameLoop
- HandleEvents
- setDirection

You will then need to make an "entryPoint" method to allow Core to load the class. For this project, this is what it looks like

```c++
extern "C"
{
    std::unique_ptr<Arcade::AGame> entryPoint()
    {
        return std::make_unique<Arcade::Nibbler>();
    }
}
```

This file is found in each src folder linked to a game. 
for the compilation to take your game into account, you will also need to edit the Cmakelist, located in the same place as this README.
```
project(Games)

set(COMMON_INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/Core/include
        include
)

add_subdirectory(Nibbler)
add_subdirectory(Snake)
->ADD YOUR GAME DIR HERE<-
```

Once your game is added to the file it will be added to the compilation
You need to create a 'Cmakelist.txt' file that will compile your library as a shadred library, in a new directory named 'pacman' for exemple. Here is an emample of a 'CMakeList.txt' file :

```
project(arcade_pacman
        VERSION 0.1.0
        DESCRIPTION "Pacman library for the arcade project"
        LANGUAGES C CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/Pacman.cpp
        ${SRC_DIR}/gameLoop.cpp
        ${SRC_DIR}/event.cpp
        ${SRC_DIR}/move.cpp
        ${SRC_DIR}/food.cpp
        ${SRC_DIR}/load.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE arcade_abstractions)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
```

You now have to continue the implementation, to have a complete and functional game