/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "abstractions/AGraphic.hpp"
#include "Core.hpp"


void Arcade::Core::gameLoop()
{
    while (_mode != CoreMode::QUIT) {
        handleEvents(_window->getEvent());
        _window->displayWindow();
    }
}
