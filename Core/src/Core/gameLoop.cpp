/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** gameLoop.cpp
*/

#include "Arcade/Core.hpp"

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
