/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.cpp
*/

#include <dlfcn.h>
#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"
#include "Arcade/RuntimeException.hpp"

constexpr char const *NO_DISPLAY = "DISPLAY environment variable is not set";
constexpr std::string_view UNKNOW_ERROR = "Unknown error";
constexpr std::string_view CORE_EXCEPT = "Core exception: ";
constexpr std::string_view RUNTIME_EXCEPT = "Runtime exception: ";

void Arcade::Core::parser(const std::string &path)
{
    if (getenv("DISPLAY") == nullptr) {
        throw CoreException{NO_DISPLAY};
    }
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        throw CoreException(dlerror());
    }
    auto *entryPointFunc = reinterpret_cast<std::unique_ptr<IRenderer> (*)()>(dlsym(handle, "entryPoint"));
    if (entryPointFunc == nullptr) {
        throw CoreException(dlerror());
    }
    _renderer = entryPointFunc();
    _handleGraphic = handle;
}

void Arcade::Core::loadGraphic() {
    const unsigned int width = 1920;
    const unsigned int height = 1080;

    _renderer->getWindow()->openWindow(width, height);
    if (_renderer->isASCII()) {
        //loadTextures(someasciiartonlyformenu, "ascii art name");
    } else {
        if (!_renderer->loadFont("assets/fonts/menu_i.ttf", "menu_i")) {
            throw RuntimeException("Cannot load fonts");
        } if (!_renderer->loadTexture("assets/textures/background.jpg", "background")) {
            throw RuntimeException("Cannot load background texture");
        }
        _renderer->createSprite("background", 0, 0, 1, 1);
        _renderer->createText("menu_i", "MENU", 50, width / 2 - 100, height / 12);
        for (unsigned int index = 0; index < _graphicLibs.size(); index++) {
            _renderer->createText("menu_i", _graphicLibs[index], 30, width * 0.6, (static_cast<float>(height / 2 - 100 + 50 * (index + 1))));
        }
        for (unsigned int index = 0; index < _gameLibs.size(); index++) {
            _renderer->createText("menu_i", _gameLibs[index], 30, width * 0.1, (static_cast<float>(height / 2 - 100 + 50 * (index + 1))));
        }
    }
}

int Arcade::Core::runArcade(const std::string &path)
{
    try {
        parser(path);
        getLibraries();
        loadGraphic();
        gameLoop();
    } catch (CoreException &e) {
        std::cerr << CORE_EXCEPT << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (const RuntimeException &e) {
        std::cerr << RUNTIME_EXCEPT << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (...) {
        std::cerr << UNKNOW_ERROR << '\n';
        return EPITECH_ERROR;
    }
    return SUCCESS;
}
