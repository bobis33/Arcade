/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** mainLoop.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/EventsManager.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Core &)>> MAP_LOGIN_EVENT = {
        {Arcade::KeyboardEvents::TEXTENTERED,
                [](Arcade::Core &core) -> void {
                    const std::string &userName = core.getRenderer()->updateTextBox();
                    core.setUserName(userName);
                }},
        {Arcade::KeyboardEvents::ENTER,
                [](Arcade::Core &core) -> void {
                    core.loadMenu();
                    core.getRenderer()->loadSound();
                    core.setMode(Arcade::CoreMode::MENU);
                }},
};

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Core &)>> MAP_COMMON_EVENT = {
        {Arcade::KeyboardEvents::ESC,
                [](Arcade::Core &core) -> void {
                    core.getRenderer()->stopSound();
                    core.getRenderer()->getWindow()->closeWindow();
                    core.setMode(Arcade::CoreMode::QUIT);
                }},
        {Arcade::KeyboardEvents::F1,
                [](Arcade::Core &core) -> void {
                    core.switchGraphicLibrary();
                    core.getRenderer()->getWindow()->clearWindow();
                }},
        {Arcade::KeyboardEvents::F2,
                [](Arcade::Core &core) -> void {
                if (core.getMode() != Arcade::CoreMode::MENU && core.getMode() != Arcade::CoreMode::LOGIN) {
                    core.loadMenu();
                    core.getRenderer()->loadSound();
                    core.setMode(Arcade::CoreMode::MENU);
                }
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
};

void Arcade::Core::mainLoop()
{
    KeyboardEvents event{KeyboardEvents::NONE};

    while (_mode != CoreMode::QUIT) {
        event = _renderer->getEvent();
        if (_mode == CoreMode::LOGIN) {
            EventManager::handleEvent<Core>(MAP_LOGIN_EVENT, *this, event);
            displayLoginScreen();
        } else if (_mode == CoreMode::MENU) {
            displayMenu();
            EventManager::handleEvent<Core>(MAP_MENU_EVENT, *this, event);
        } else if (_mode == CoreMode::GAME) {
            _game->displayGame();
            _game->handleEvents(event);
        }
        EventManager::handleEvent<Core>(MAP_COMMON_EVENT, *this, event);
        _renderer->getWindow()->displayWindow();
    }
}
