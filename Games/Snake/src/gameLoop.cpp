/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** gameLoop.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::gameLoop()
{
    if (!_isAscii) {
        _renderer->displaySprite("background_snake");
        _renderer->displaySprite("Sugar");
        _renderer->displaySprite("head");
        displaySnake();
    }
    _renderer->displayText("Player:");
    _renderer->displayText(_userName);
    _renderer->displayText("Score:");
    _renderer->displayText(std::to_string(_score));
    _renderer->displayText("Press F2 to go back to the menu");
    if (_gameMode == GameMode::GAME_OVER) {
        _renderer->displayText("Game Over");
    }

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += _moveSpeed;
    if (!_isAscii) {
        moveSnake();
        moveBody();
        checkLose();
        for (size_t i = NB_MOVES; i > 0; i--)
            _prevDirection[i] = _prevDirection[i - 1];

        _prevDirection[0] = _direction;
        isEating();
    } else {
        _renderer->createText("0", std::to_string(_score), 0, 6, 70);
    }
}
