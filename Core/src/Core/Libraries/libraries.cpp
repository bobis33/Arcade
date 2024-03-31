/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libraries.cpp
*/

#include <algorithm>
#include <filesystem>

#include "Arcade/Core.hpp"

static const std::vector<std::string> GRAPHIC_LIBS = {"arcade_ncurses.so", "arcade_sdl2.so", "arcade_sfml.so"};
static const std::vector<std::string> GAME_LIBS    = {"arcade_nibbler.so", "arcade_snake.so"};

static bool pushLibrary(const std::vector<std::string> &libs, std::vector<std::string> &libsToPush, const std::string &libname) {
    if (std::ranges::find(libs.begin(), libs.end(), libname) != libs.end()) {
        libsToPush.emplace_back(libname);
        return true;
    }
    return false;
}

void Arcade::Core::getLibraries(const std::string &libPath) {
    namespace fs = std::filesystem;

    for (const auto& entry : fs::directory_iterator(LIB_PATH)) {
        std::string libname = entry.path().filename().string();
        if (!pushLibrary(GRAPHIC_LIBS, _graphicLibs, libname) && !pushLibrary(GAME_LIBS, _gameLibs, libname)) {
            throw CoreException("Unknown library: " + libname);
        }
    }
    size_t index = 0;
    std::string activeLib = fs::path(libPath).filename().string();
    for (const auto& lib : _graphicLibs) {
        if (lib == activeLib) {
            _currentGraphicIndex = index;
            break;
        }
        index++;
    }
}
