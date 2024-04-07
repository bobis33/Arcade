/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::resetGame()
{
    _mapPosition = {16, 9};
    _direction = Direction::RIGHT;
    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
    _snakeSize = 1;
    std::string body_string = "body";
    std::pair<size_t, size_t> body_position = {16, 8};
    for (size_t i = 0; i < 3; i++) {
        _prevDirection[i] = Direction::RIGHT;
        _snakeSize++;
        body_string = "body";
        body_string += std::to_string(_snakeSize);
        if (!_renderer->loadTexture("assets/textures/nibbler/body.png", body_string))
            throw std::runtime_error("Could not load texture body");
        body_position.second = 8 - i;
        _mapPositionBody[_snakeSize] = body_position;
        _renderer->createSprite(body_string, _map[body_position.first][body_position.second].first, _map[body_position.first][body_position.second].second, 1, 1);
    }
    _moveSpeed = MOVE_SPEED;
    _increaseSpeed = 0;
    _mapPositionFood.clear();
}

void Arcade::Nibbler::checkWin()
{
    if (_foodLeft == 0) {
        _lvl = 2;
        resetGame();
        createMap();
    }
}

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
