/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libraries.cpp
*/

#include <algorithm>
#include <dirent.h>
#include <dlfcn.h>

#include "Arcade/Core.hpp"

static const std::vector<std::string> graphics_lib = {"arcade_ncurses.so", "arcade_sdl2.so", "arcade_sfml.so"};
static const std::vector<std::string> games_lib    = {"arcade_nibbler.so", "arcade_snake.so"};

void Arcade::Core::switchGraphicLib() {
    for (size_t index = 0; index < _graphicLibs.size(); index++) {
        if (_graphicLibs[index] == _graphicLibs[_currentGraphicIndex]) {
            _currentGraphicIndex = index;
        }
    }
    _currentGraphicIndex = (_currentGraphicIndex + 1) % _graphicLibs.size();

    _renderer->getWindow()->closeWindow();
    _renderer.reset();
    dlclose(_handleGraphic);
    parser("lib/" + _graphicLibs[_currentGraphicIndex]);
    loadGraphic();
}

void Arcade::Core::getLibraries() {
    struct dirent *entry{nullptr};
    DIR *dir= opendir("./lib");
    std::string libname;

    if (dir == nullptr)
        throw CoreException{"Cannot open lib directory"};

    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_name[0] != '.') {
            libname = entry->d_name;
            if (std::find(graphics_lib.begin(), graphics_lib.end(), libname) != graphics_lib.end()) {
                _graphicLibs.push_back(libname);
            } else if (std::find(games_lib.begin(), games_lib.end(), libname) != games_lib.end()) {
                _gameLibs.push_back(libname);
            } else {
                throw CoreException{"Unknown library"};
            }
        }
    }
    closedir(dir);
}