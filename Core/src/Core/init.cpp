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

int Arcade::Core::runArcade(const std::string &path)
{
    const unsigned int width = 1920;
    const unsigned int height = 1080;
    try {
        parser(path);
        _window->openWindow(width, height);
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
