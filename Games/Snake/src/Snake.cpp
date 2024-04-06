/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::checkLose()
{
    for (size_t i = 3; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
            _gameMode = GameMode::GAME_OVER;
        }
    }
}

std::pair<size_t, size_t> Arcade::Snake::getBodyPosition()
{
    std::pair<unsigned long, unsigned long> bodyPosition = _mapPosition;

    for (size_t i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                if (bodyPosition.first == 9) {
                    bodyPosition.first = 0;
                } else {
                    bodyPosition.first++;
                }
                break;
            case Direction::DOWN:
                if (bodyPosition.first == 0) {
                    bodyPosition.first = 9;
                } else {
                    bodyPosition.first--;
                }
                break;
            case Direction::LEFT:
                if (bodyPosition.second == 11) {
                    bodyPosition.second = 0;
                } else {
                    bodyPosition.second++;
                }
                break;
            case Direction::RIGHT:
                if (bodyPosition.second == 0) {
                    bodyPosition.second = 11;
                } else {
                    bodyPosition.second--;
                }
                break;
            default:
                break;
        }
    }
    return bodyPosition;
}

void Arcade::Snake::displaySnake()
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
