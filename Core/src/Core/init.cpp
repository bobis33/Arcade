/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.cpp
*/

#include <dlfcn.h>
#include "abstractions/AGraphic.hpp"
#include "Core.hpp"
#include "Constants.hpp"


void Arcade::Core::parser(const std::string &path)
{
    if (!getenv("DISPLAY"))
        throw CoreException{NO_DISPLAY.data()};

    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        throw CoreException(dlerror());
    }
    auto *entryPointFunc = reinterpret_cast<std::unique_ptr<AGraphic> (*)()>(dlsym(handle, "entryPoint"));
    if (!entryPointFunc) {
        throw CoreException(dlerror());
    }
    _window = entryPointFunc();
}

int Arcade::Core::runArcade(const std::string &path)
{
    try {
        parser(path);
        gameLoop();
    } catch (CoreException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EPITECH_ERROR;
    }
    return SUCCESS;
}
