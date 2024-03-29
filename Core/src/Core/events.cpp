/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** events.cpp
*/

#include <map>
#include <functional>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Core &)>> MAP_GAME_EVENT = {
        {Arcade::KeyboardEvents::ESC,
                [](Arcade::Core &core) -> void {
                    // core.getRenderer()->stopSound();
                    core.getRenderer()->getWindow()->closeWindow();
                    core.setMode(Arcade::CoreMode::QUIT);
                }},
        {Arcade::KeyboardEvents::F1,
                [](Arcade::Core &core) -> void {
                    core.switchGraphicLibrary();
                }},
};

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Core &)>> MAP_MENU_EVENT = {
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Core &core) -> void {
                    core.moveCursorUp();
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Core &core) -> void {
                    core.moveCursorDown();
                }},
            {Arcade::KeyboardEvents::ENTER,
                [](Arcade::Core &core) -> void {
                    core.setMode(Arcade::CoreMode::GAME);
                    core.getRenderer()->stopSound();
                    core.launchGame();
                }},
        {Arcade::KeyboardEvents::ESC,
                [](Arcade::Core &core) -> void {
                    core.getRenderer()->stopSound();
                    core.getRenderer()->getWindow()->closeWindow();
                    core.setMode(Arcade::CoreMode::QUIT);
                }},
        {Arcade::KeyboardEvents::F1,
                [](Arcade::Core &core) -> void {
                    core.switchGraphicLibrary();
                }},
};

void Arcade::Core::handleEvents(const KeyboardEvents &event)
{
    if (_mode == CoreMode::GAME) {
        auto map_event = MAP_GAME_EVENT.find(event);
        if (map_event != MAP_GAME_EVENT.end()) {
            map_event->second(*this);
        }
    } else if (_mode == CoreMode::MENU) {
        auto map_event = MAP_MENU_EVENT.find(event);
        if (map_event != MAP_MENU_EVENT.end()) {
            map_event->second(*this);
        }
    }
}
