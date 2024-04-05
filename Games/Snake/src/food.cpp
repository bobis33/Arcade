/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** food.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::replaceFood()
{
    bool isOnSnake = true;

    while (isOnSnake) {
        isOnSnake = false;
        _mapPositionFood = {randomize(0, 9), randomize(0, 11)};
        for (size_t i = 0; i < _snakeSize + 2; i++) {
            if (_mapPositionFood.first == _mapPositionBody[i].first && _mapPositionFood.second == _mapPositionBody[i].second) {
                isOnSnake = true;
                break;
            }
        }
    }
    _renderer->moveSprite("Sugar", _map[_mapPositionFood.first][_mapPositionFood.second].first, _map[_mapPositionFood.first][_mapPositionFood.second].second);
}

void Arcade::Snake::isEating()
{
    if (_mapPosition.first == _mapPositionFood.first && _mapPosition.second == _mapPositionFood.second) {
        _snakeSize++;
        _score += randomize(10, 50);
        if (_score % 2 == 0)
            _score =  _score + (_score / 5);
        _renderer->createText("menu_i", std::to_string(_score), 30, 1350, 350);
        std::string bodystring{"body"};
        bodystring += std::to_string(_snakeSize);
        if (!_renderer->loadTexture("assets/textures/snake/body.png", bodystring))
            throw std::runtime_error("Could not load texture body");
        _bodyPosition = getBodyPosition();
        _mapPositionBody[_snakeSize] = _bodyPosition;
        _renderer->createSprite(bodystring, _map[_bodyPosition.first][_bodyPosition.second].first, _map[_bodyPosition.first][_bodyPosition.second].second, 1, 1);
        replaceFood();
        _increaseSpeed++;
        if (_increaseSpeed >= 5 && _moveSpeed > 100) {
            _increaseSpeed = 0;
            _moveSpeed -= 50;
        }
    }
}
