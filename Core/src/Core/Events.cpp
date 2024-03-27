/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Events.cpp
*/

#include <map>
#include <functional>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

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
                    core.getRenderer()->getWindow()->closeWindow();
                    core.setMode(Arcade::CoreMode::QUIT);
                }},
        {Arcade::GameEvent::SWITCH_GRAPHIC,
                [](Arcade::Core &core) -> void {
                    core.switchGraphicLib();
                }},
};

void Arcade::Core::handleEvents(const GameEvent &event)
{
    auto map_event = MAP_EVENT.find(event);

    if (map_event != MAP_EVENT.end()) {
        map_event->second(*this);
    }
}
