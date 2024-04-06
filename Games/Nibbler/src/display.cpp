/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::displayFood()
{
    std::string food_string{"Sugar"};

    for (size_t i = 0; i <= _nbFood; i++) {
        if (_mapPositionFood[i].second == true) {
            food_string = "Sugar";
            food_string += std::to_string(i);
            _renderer->displaySprite(food_string);
        }
    }
}

void Arcade::Nibbler::displaySnake()
{
    std::string body_string{"body"};

    if (_snakeSize > 1) {
        for (size_t i = 1; i <= _snakeSize; i++) {
            body_string = "body";
            body_string += std::to_string(i);
            _renderer->displaySprite(body_string);
        }
    }
    _renderer->displaySprite("head");
}
