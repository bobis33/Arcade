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
    _window = entryPointFunc();
}

void Arcade::Core::loadGraphic() {
    const unsigned int width = 1920;
    const unsigned int height = 1080;

    _window->openWindow(width, height);
    if (_window->isASCII()) {
        //loadTextures(someasciiartonlyformenu, "ascii art name");
    } else {
        if (!_window->loadFont("assets/fonts/menu_i.ttf", "menu_i")) {
            throw std::runtime_error("Cannot load fonts");
        } if (!_window->loadTexture("assets/textures/background.jpg", "background")) {
            throw std::runtime_error("Cannot load background texture");
        }
        _window->createSprite("background", 0, 0, 1, 1);
        _window->createText("menu_i", "MENU", 50, width / 2 - 100, height / 2 - 100);
    }
}

int Arcade::Core::runArcade(const std::string &path)
{
    try {
        parser(path);
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
