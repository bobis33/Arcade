/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** food.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::createFood()
{
    size_t food_index = 0;
    std::string food_string{"Sugar"};

    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            if (_mapPositionWall[i][j] == 'o') {
                _mapPositionFood.push_back({{i, j}, true});
                food_index++;
            }
        }
    }
    _nbFood = food_index;
    for (size_t i = 0; i <= _nbFood; i++) {
        food_string = "Sugar";
        food_string += std::to_string(i);
        if (!_renderer->loadTexture("assets/textures/nibbler/sugar.png", food_string))
            throw std::runtime_error("Could not load texture sugar");
        _renderer->createSprite(food_string, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].first, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].second, 1, 1);
    }
}

void Arcade::Nibbler::isEating()
{
    for (size_t i = 0; i <= _nbFood; i++) {
        if (_mapPosition.first == _mapPositionFood[i].first.first && _mapPosition.second == _mapPositionFood[i].first.second && _mapPositionFood[i].second == true) {
            _mapPositionFood[i].second = false;
            _snakeSize++;
            _score += 100;
            std::string bodystring{"body"};
            bodystring += std::to_string(_snakeSize);
            if (!_renderer->loadTexture("assets/textures/nibbler/body.png", bodystring))
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
