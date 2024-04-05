/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler
*/

#include "Arcade/Nibbler.hpp"

bool Arcade::Nibbler::findDirection(const Direction &dir)
{
    int count = 0;
    Arcade::Direction newDir = dir;
    if (dir == Direction::UP) {
        if (_mapPosition.second != 0 && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X') {
            newDir = Direction::LEFT;
            count++;
        }
        if (_mapPosition.second != 16 && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X') {
            newDir = Direction::RIGHT;
            count++;
        }
        if (count == 1) {
            setDirection(newDir);
            return true;
        } else {
            return false;
        }
    } else if (dir == Direction::DOWN) {
        if (_mapPosition.second != 0 && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X') {
            newDir = Direction::LEFT;
            count++;
        }
        if (_mapPosition.second != 16 && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X') {
            newDir = Direction::RIGHT;
            count++;
        }
        if (count == 1) {
            setDirection(newDir);
            return true;
        } else {
            return false;
        }
    } else if (dir == Direction::LEFT) {
        if (_mapPosition.first != 0 && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X') {
            newDir = Direction::UP;
            count++;
        }
        if (_mapPosition.first != 16 && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X') {
            newDir = Direction::DOWN;
            count++;
        }
        if (count == 1) {
            setDirection(newDir);
            return true;
        } else {
            return false;
        }
    } else if (dir == Direction::RIGHT) {
        if (_mapPosition.first != 0 && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X') {
            newDir = Direction::UP;
            count++;
        }
        if (_mapPosition.first != 16 && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X') {
            newDir = Direction::DOWN;
            count++;
        }
        if (count == 1) {
            setDirection(newDir);
            return true;
        } else {
            return false;
        }
    }
    return false;
}



void Arcade::Nibbler::gameLoop()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("map1");
    _renderer->displaySprite("head");
    _renderer->displayText("Player:");
    _renderer->displayText(_userName);
    _renderer->displayText("Score:");
    _renderer->displayText(std::to_string(_score));
    _renderer->displayText("Press F2 to go back to the menu");
    displaySnake();
    displayFood();
    if (_gameMode == GameMode::GAME_OVER) {
        _renderer->displayText("Game Over");
    }

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += _moveSpeed;
    checkIfCanMove(_mapPosition, _direction);
    if (_canMove == false) {
        if (findDirection(_direction) == false)
            return;
    }
    moveSnake();
    moveBody();
    checkLose();
    for (size_t i = NB_MOVES; i > 0; i--)
        _prevDirection[i] = _prevDirection[i - 1];
    _prevDirection[0] = _direction;
    isEating();
}
