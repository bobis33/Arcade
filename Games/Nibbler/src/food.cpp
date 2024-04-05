/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** food
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::isEating()
{
    //if (_mapPosition.first == _mapPositionFood.first && _mapPosition.second == _mapPositionFood.second) {
    //    _snakeSize++;
    //    _score += 100;
    //    _renderer->createText("menu_i", std::to_string(_score), 30, 1350, 350);
    //    std::string bodystring{"body"};
    //    bodystring += std::to_string(_snakeSize);
    //    if (!_renderer->loadTexture("assets/textures/snake/body.png", bodystring))
    //        throw std::runtime_error("Could not load texture body");
    //    _bodyPosition = getBodyPosition();
    //    _mapPositionBody[_snakeSize] = _bodyPosition;
    //    _renderer->createSprite(bodystring, _map[_bodyPosition.first][_bodyPosition.second].first, _map[_bodyPosition.first][_bodyPosition.second].second, 1, 1);
    //    _increaseSpeed++;
    //    if (_increaseSpeed >= 5 && _moveSpeed > 100) {
    //        _increaseSpeed = 0;
    //        _moveSpeed -= 50;
    //    }
    //}

    for (size_t i = 0; i <= _nbFood; i++) {
        if (_mapPosition.first == _mapPositionFood[i].first.first && _mapPosition.second == _mapPositionFood[i].first.second) {
            _mapPositionFood[i].second = false;
            _snakeSize++;
            _score += 100;
            _renderer->createText("menu_i", std::to_string(_score), 30, 1350, 350);
            std::string bodystring{"body"};
            bodystring += std::to_string(_snakeSize);
            if (!_renderer->loadTexture("assets/textures/snake/body.png", bodystring))
                throw std::runtime_error("Could not load texture body");
            _bodyPosition = getBodyPosition();
            _mapPositionBody[_snakeSize] = _bodyPosition;
            _renderer->createSprite(bodystring, _map[_bodyPosition.first][_bodyPosition.second].first, _map[_bodyPosition.first][_bodyPosition.second].second, 1, 1);
            _increaseSpeed++;
            if (_increaseSpeed >= 5 && _moveSpeed > 100) {
                _increaseSpeed = 0;
                _moveSpeed -= 50;
            }
        }
    }
}
