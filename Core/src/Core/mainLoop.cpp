/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** mainLoop.cpp
*/

#include "Arcade/Core.hpp"

void Arcade::Core::mainLoop()
{
    while (_mode != CoreMode::QUIT) {
        if (_mode == CoreMode::MENU) {
            displayMenu();
        } else if (_mode == CoreMode::GAME) {}
        handleEvents(_renderer->getEvent());
        _renderer->getWindow()->displayWindow();
    }
}
