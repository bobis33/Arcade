/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** switch.cpp
*/

#include <dlfcn.h>

#include "Arcade/Core.hpp"
#include "Arcade/RuntimeException.hpp"

void Arcade::Core::closeGameLibrary()
{
    _game->stop();
    _game.reset();
    dlclose(_handleGame);
}

void Arcade::Core::switchGraphicLibrary()
{
    _renderer->stopSound();
    _currentGraphicIndex = getNextLibIndex(_graphicLibs, _currentGraphicIndex);
    switchLib<IRenderer>(LIB_PATH + _graphicLibs[_currentGraphicIndex]);
    if (_mode == CoreMode::GAME)
        setMode(CoreMode::MENU);
    _renderer->getWindow()->openWindow(WIDTH, HEIGHT);
    _renderer->setSize(WIDTH, HEIGHT);
    if (!_renderer->loadFont("assets/fonts/menu_i.ttf", "menu_i"))
        throw RuntimeException("Cannot load fonts");
    if (_mode == CoreMode::MENU) {
        loadMenu();
        _renderer->loadSound("assets/sounds/menu.ogg");
    } else {
        loadLogin();
    }
}

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
            _renderer->stopSound();
            _renderer->getWindow()->closeWindow();
            _renderer.reset();
            dlclose(_handleGraphic);
        }
        _renderer = std::move(entryPointFunc());
        _handleGraphic = handle;
    } else if constexpr (std::is_same_v<T, IGame>) {
        if (_game != nullptr) {
            _game.reset();
            dlclose(_handleGame);
        }
        _game = std::move(entryPointFunc());
        _handleGame = handle;
    } else {
        throw CoreException("Invalid library type");
    }
}

template void Arcade::Core::switchLib<Arcade::IRenderer>(const std::string &);
template void Arcade::Core::switchLib<Arcade::IGame>(const std::string &);
