/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include <map>
#include <functional>
#include <dlfcn.h>
#include "Core.hpp"

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
        {Arcade::GameEvent::PAUSE,
                [](Arcade::Core &core) -> void {
                    std::cout << "PAUSE" << std::endl;
                }},
        {Arcade::GameEvent::QUIT,
                [](Arcade::Core &core) -> void {
                    std::cout << "QUIT" << std::endl;
                }},
        */
};

void Arcade::Core::handleEvents()
{
    while (_gameEvent != GameEvent::NONE)
        for (auto mapEvent : MAP_EVENT)
            if (mapEvent.first == _gameEvent) {
                mapEvent.second(*this);
                return;
            }
}

void Arcade::Core::gameLoop()
{
    while (_gameMode != GameMode::QUIT) {
        handleEvents();
    }
}

void Arcade::Core::parser(const std::string &path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        throw CoreException{std::string(dlerror())};
    }
    dlclose(handle);
}
