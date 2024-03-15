/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include <map>
#include <functional>
#include <dlfcn.h>
#include <memory>
#include "Core.hpp"
#include "abstractions/AGraphic.hpp"

static const std::map<const Arcade::GameEvent, std::function<void(Arcade::Core &)>> MAP_EVENT = {
        /*
        {Arcade::GameEvent::UP,
                [](Arcade::Core &core) -> void {
                    std::cout << "UP" << std::endl;
                }},
        {Arcade::GameEvent::DOWN,
                [](Arcade::Core &core) -> void {
                    std::cout << "DOWN" << std::endl;
                }},
        {Arcade::GameEvent::LEFT,
                [](Arcade::Core &core) -> void {
                    std::cout << "LEFT" << std::endl;
                }},
        {Arcade::GameEvent::RIGHT,
                [](Arcade::Core &core) -> void {
                    std::cout << "RIGHT" << std::endl;
                }},
        {Arcade::GameEvent::SHOOT,
                [](Arcade::Core &core) -> void {
                    std::cout << "SHOOT" << std::endl;
                }},
                                        */
        {Arcade::GameEvent::PAUSE,
                [](Arcade::Core &core) -> void {
                    core.setMode(Arcade::CoreMode::PAUSE);
                }},
        {Arcade::GameEvent::QUIT,
                [](Arcade::Core &core) -> void {
                    core.closeWindow();
                    core.setMode(Arcade::CoreMode::QUIT);
                }},
};

void Arcade::Core::handleEvents(GameEvent event)
{
    for (auto &mapEvent: MAP_EVENT)
        if (mapEvent.first == event) {
            mapEvent.second(*this);
            return;
        }
}

void Arcade::Core::gameLoop()
{
    while (_mode != CoreMode::QUIT) {
        handleEvents(_window->getEvent());
        _window->displayWindow();
    }
}

void Arcade::Core::parser(const std::string &path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        throw CoreException{std::string(dlerror())};
    }
    auto *entryPointFunc = reinterpret_cast<std::unique_ptr<AGraphic> (*)()>(dlsym(handle, "entryPoint"));
    if (!entryPointFunc) {
        throw CoreException{std::string(dlerror())};
    }
    _window = entryPointFunc();
    gameLoop();
}
