/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** run.cpp
*/

#include <filesystem>
#include <ranges>

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"
#include "Arcade/RuntimeException.hpp"

void Arcade::Core::loadRenderer(const std::string &path)
{
    switchLib<IRenderer>(path);
    if (_renderer->isASCII()) {
        _renderer->setSize(80, 40);
        _renderer->getWindow()->openWindow(80, 40);
    } else {
        _renderer->setSize(WIDTH, HEIGHT);
        _renderer->getWindow()->openWindow(WIDTH, HEIGHT);
    }
    if (!_renderer->loadFont("assets/fonts/menu_i.ttf", "menu_i"))
        throw RuntimeException{"Cannot load fonts"};
    loadMenu();
    loadLogin();
}

int Arcade::Core::runArcade(const std::string &path)
{
    std::string activeLib{};

    try {
        if (getenv("DISPLAY") == nullptr)
            throw CoreException{"DISPLAY environment variable is not set"};
        getLibraries(path);
        activeLib = std::filesystem::path(path).filename().string();
        if (std::ranges::find(_graphicLibs, activeLib) == _graphicLibs.end())
            throw CoreException{"Must be a graphic library: " + activeLib};
        loadRenderer(path);
        mainLoop();
    } catch (const CoreException &e) {
        std::cerr << "Core exception: " << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (const RuntimeException &e) {
        std::cerr << "Runtime exception: " << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (...) {
        std::cerr << "Unknown error" << '\n';
        return EPITECH_ERROR;
    }
    return SUCCESS;
}
