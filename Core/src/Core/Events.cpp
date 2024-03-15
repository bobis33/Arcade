/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Events.cpp
*/

#include <map>
#include <functional>
#include "abstractions/AGraphic.hpp"
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
