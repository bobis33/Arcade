/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::displayMenu() {
    _renderer->displaySprite("background");
    _renderer->displayText("MENU");
    for (const auto & graphicLibrarie : _graphicLibs) {
        _renderer->displayText(graphicLibrarie);
    }
    for (const auto & gameLibrarie : _gameLibs) {
        _renderer->displayText(gameLibrarie);
    }
}

void Arcade::Core::gameLoop()
{
    while (_mode != CoreMode::QUIT) {
        if (_mode == CoreMode::MENU) {
            displayMenu();
        }
        /*if (_mode == CoreMode::GAME) {
         *   _game->update();
         *   _game->display();
         *   }
         */
        handleEvents(_renderer->getEvent());
        _renderer->getWindow()->displayWindow();
    }
}
