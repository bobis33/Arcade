/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** switch.cpp
*/

#include <algorithm>
#include <dlfcn.h>
#include <filesystem>

#include "Arcade/Constants.hpp"
#include "Arcade/Core.hpp"


template<typename T>
void Arcade::Core::switchLib(const std::string &libPath)
{
    void *handle = dlopen(libPath.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        throw CoreException(dlerror());
    }
    auto *entryPointFunc = reinterpret_cast<std::unique_ptr<T> (*)()>(dlsym(handle, "entryPoint"));
    if (entryPointFunc == nullptr) {
        throw CoreException(dlerror());
    }
    if constexpr (std::is_same_v<T, IRenderer>) {
        if (_renderer != nullptr) {
            _renderer->getWindow()->closeWindow();
            _renderer.reset();
            dlclose(_handleGraphic);
        }
        _renderer = std::move(entryPointFunc());
        _handleGraphic = handle;
    } else if constexpr (std::is_same_v<T, IGame>) {
        if (_game != nullptr) {
            dlclose(_handleGame);
            _handleGame = nullptr;
        }
        _game = std::move(entryPointFunc());
        _handleGame = handle;
    } else {
        throw CoreException("Invalid library type");
    }
}


size_t Arcade::Core::getNextLibIndex(std::vector<std::string> &libs, size_t currentIndex) {
    for (size_t index = 0; index < libs.size(); index++) {
        if (libs[index] == libs[currentIndex]) {
            currentIndex = index;
        }
    }
    return (currentIndex + 1) % libs.size();
}

void Arcade::Core::switchGraphicLibrary() {
    _currentGraphicIndex = getNextLibIndex(_graphicLibs, _currentGraphicIndex);

    switchLib<IRenderer>(LIB_PATH + _graphicLibs[_currentGraphicIndex]);
    _renderer->getWindow()->openWindow(WIDTH, HEIGHT);
    loadMenu();
}


template void Arcade::Core::switchLib<Arcade::IRenderer>(const std::string &);
template void Arcade::Core::switchLib<Arcade::IGame>(const std::string &);
