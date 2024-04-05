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
                    core.closeGameLibrary();
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
                    core.getRenderer()->stopSound();
                    core.launchGame();
                    core.setMode(Arcade::CoreMode::GAME);
                }},
};

void Arcade::Core::mainLoop()
{
    KeyboardEvents event{KeyboardEvents::NONE};

    while (_mode != CoreMode::QUIT) {
        event = _renderer->getEvent();

        switch (_mode) {
            case CoreMode::LOGIN:
                displayLoginScreen();
                EventManager::handleEvent<Core>(MAP_LOGIN_EVENT, *this, event);
                break;
            case CoreMode::MENU:
                displayMenu();
                EventManager::handleEvent<Core>(MAP_MENU_EVENT, *this, event);
                break;
            case CoreMode::GAME:
                _game->gameLoop();
                _game->handleEvents(event);
                break;
            case CoreMode::QUIT:
                _renderer->stopSound();
                _renderer->getWindow()->closeWindow();
                return;

            default:
                break;
        }
        _renderer->getWindow()->displayWindow();
        EventManager::handleEvent<Core>(MAP_COMMON_EVENT, *this, event);
    }
}
