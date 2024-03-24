/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::displayMenu() {
    _window->displaySprite("background");
    _window->displayText("MENU");
}

void Arcade::Core::gameLoop()
{
    while (_mode != CoreMode::QUIT) {
        _window->displayWindow();
        handleEvents(_window->getEvent());
        if (_mode == CoreMode::MENU) {
            displayMenu();
        }
        /*if (_mode == CoreMode::GAME) {
         *   _game->update();
         *   _game->display();
         *   }
         */
    }
}
