/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** run.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"
#include "Arcade/RuntimeException.hpp"

static constexpr std::string_view NO_DISPLAY = "DISPLAY environment variable is not set";

static constexpr std::string_view UNKNOW_ERROR = "Unknown error";
static constexpr std::string_view CORE_EXCEPT = "Core exception: ";
static constexpr std::string_view RUNTIME_EXCEPT = "Runtime exception: ";

void Arcade::Core::loadRenderer(const std::string &path)
{
    switchLib<IRenderer>(path);
    getLibraries(path);
    _renderer->setSize(WIDTH, HEIGHT);
    _renderer->getWindow()->openWindow(WIDTH, HEIGHT);
    if (!_renderer->loadFont("assets/fonts/menu_i.ttf", "menu_i"))
        throw RuntimeException("Cannot load fonts");
    loadMenu();
    loadLogin();
}

int Arcade::Core::runArcade(const std::string &path)
{
    try {
        if (getenv("DISPLAY") == nullptr)
            throw CoreException{NO_DISPLAY.data()};
        loadRenderer(path);
        mainLoop();
    } catch (const CoreException &e) {
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
