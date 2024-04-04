/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** gameLoop.cpp
*/

#include "Arcade/Nibbler.hpp"


void Arcade::Nibbler::gameLoop()
{
    _renderer->displayText("Player:");
    _renderer->displayText(_userName);
    _renderer->displayText("Score:");
    _renderer->displayText(std::to_string(_score));
    _renderer->displayText("Press F2 to go back to the menu");
    _renderer->displaySprite("Sugar");
    if (_gameMode == GameMode::GAME_OVER) {
        _renderer->displayText("Game Over");
    }

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += MOVE_SPEED;
}
