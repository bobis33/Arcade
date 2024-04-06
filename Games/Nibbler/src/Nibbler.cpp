/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler
*/

#include "Arcade/Nibbler.hpp"

bool Arcade::Nibbler::findDirection(const Direction &direction)
{
    int count = 0;
    Direction newDirection{};

    switch (direction) {
        case Direction::UP:
            if (_mapPosition.second != 0 && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X') {
                newDirection = Direction::LEFT;
                count++;
            }
            if (_mapPosition.second != 16 && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X') {
                newDirection = Direction::RIGHT;
                count++;
            }
            if (count == 1) {
                setDirection(newDirection);
                return true;
            }
            return false;
        case Direction::DOWN:
            if (_mapPosition.second != 0 && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X') {
                newDirection = Direction::LEFT;
                count++;
            }
            if (_mapPosition.second != 16 && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X') {
                newDirection = Direction::RIGHT;
                count++;
            }
            if (count == 1) {
                setDirection(newDirection);
                return true;
            }
            return false;
        case Direction::LEFT:
            if (_mapPosition.first != 0 && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X') {
                newDirection = Direction::UP;
                count++;
            }
            if (_mapPosition.first != 16 && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X') {
                newDirection = Direction::DOWN;
                count++;
            }
            if (count == 1) {
                setDirection(newDirection);
                return true;
            }
            return false;
        case Direction::RIGHT:
            if (_mapPosition.first != 0 && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X') {
                newDirection = Direction::UP;
                count++;
            }
            if (_mapPosition.first != 16 && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X') {
                newDirection = Direction::DOWN;
                count++;
            }
            if (count == 1) {
                setDirection(newDirection);
                return true;
            }
            return false;

        default:
            return false;
    }
}

void Arcade::Nibbler::checkLose()
{
    for (size_t i = 4; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
            _gameMode = GameMode::GAME_OVER;
        }
    }
}

std::pair<size_t, size_t> Arcade::Nibbler::getBodyPosition()
{
    std::pair<unsigned long, unsigned long> body_position = _mapPosition;

    for (size_t i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                body_position.first++;
                break;
            case Direction::DOWN:
                body_position.first--;
                break;
            case Direction::LEFT:
                body_position.second++;
                break;
            case Direction::RIGHT:
                body_position.second--;
                break;
            default:
                break;
        }
    }
    return body_position;
}
