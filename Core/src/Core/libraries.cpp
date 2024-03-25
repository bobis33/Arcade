/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libraries.cpp
*/

#include <iostream>
#include <algorithm>
#include <dirent.h>

#include "Arcade/Core.hpp"

static const std::vector<std::string> graphics_lib = {"arcade_ncurses.so", "arcade_sfml.so", "arcade_sdl2.so"};
static const std::vector<std::string> games_lib    = {""};

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
                _graphicLibraries.push_back(libname);
            } else if (std::find(games_lib.begin(), games_lib.end(), libname) != games_lib.end()) {
                _gameLibraries.push_back(libname);
            } else {
                throw CoreException{"Unknown library"};
            }
        }
    }
}