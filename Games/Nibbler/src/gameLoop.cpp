/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** gameLoop.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::gameLoop()
{
    if (!_isAscii) {
        _renderer->displaySprite("background_snake");
        if (_lvl == 1)
            _renderer->displaySprite("map1");
        else if (_lvl == 2)
            _renderer->displaySprite("map2");
        _renderer->displaySprite("head");
        displaySnake();
        displayFood();
    }
    _renderer->displayText("Player:");
    _renderer->displayText(_userName);
    _renderer->displayText("Score:");
    _renderer->displayText(std::to_string(_score));
    _renderer->displayText("Press F2 to go back to the menu");
    if (_gameMode == GameMode::GAME_OVER)
        _renderer->displayText("Game Over");

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += _moveSpeed;
    if (_isAscii) {
        _renderer->createText("0", std::to_string(_score), 0, 6, 70);
    } else {
        checkIfCanMove(_mapPosition, _direction);
        if (!_canMove) {
            if (!findDirection(_direction))
                return;
        }
        moveSnake();
        moveBody();
        checkLose();
        checkWin();
        for (size_t i = NB_MOVES; i > 0; i--)
            _prevDirection[i] = _prevDirection[i - 1];
        _prevDirection[0] = _direction;
        isEating();
        _renderer->createText("menu_i", std::to_string(_score), 30, BILLBOARD_POSITION, 350);
    }
}
