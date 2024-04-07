/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** move.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::setDirection(const Direction &dir)
{
    if (dir == Direction::UP && _direction != Direction::DOWN && _mapPosition.first > 0 && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X') {
        _direction = dir;
    } else if (dir == Direction::DOWN && _direction != Direction::UP && _mapPosition.first < 16 && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X') {
        _direction = dir;
    } else if (dir == Direction::LEFT && _direction != Direction::RIGHT && _mapPosition.second > 0 && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X') {
        _direction = dir;
    } else if (dir == Direction::RIGHT && _direction != Direction::LEFT && _mapPosition.second < 16 && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X') {
        _direction = dir;
    }
}

void Arcade::Nibbler::checkIfCanMove(std::pair<size_t, size_t> pos, const Direction &direction)
{
    if (direction == Direction::UP) {
        _canMove = pos.first != 0 && _mapPositionWall[pos.first - 1][pos.second] != 'X';
    } else if (direction == Direction::DOWN) {
        _canMove = pos.first != 16 && _mapPositionWall[pos.first + 1][pos.second] != 'X';
    } else if (direction == Direction::LEFT) {
        _canMove = pos.second != 0 && _mapPositionWall[pos.first][pos.second - 1] != 'X';
    } else if (direction == Direction::RIGHT) {
        _canMove = pos.second != 16 && _mapPositionWall[pos.first][pos.second + 1] != 'X';
    }
}

void Arcade::Nibbler::moveBody()
{
    std::string body_string{"body"};
    std::string body_string_corner{"body"};
    for (size_t i = 1; i <= _snakeSize; i++) {
        body_string = "body";
        body_string_corner = "body";
        body_string += std::to_string(i);
        body_string_corner += std::to_string(i + 2);
        if (_prevDirection[i - 1] == Direction::UP && _prevDirection[i] == Direction::RIGHT) {
            _renderer->loadTexture("assets/textures/nibbler/corner0.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::UP && _prevDirection[i] == Direction::LEFT) {
            _renderer->loadTexture("assets/textures/nibbler/corner3.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::DOWN && _prevDirection[i] == Direction::RIGHT) {
            _renderer->loadTexture("assets/textures/nibbler/corner3.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::DOWN && _prevDirection[i] == Direction::LEFT) {
            _renderer->loadTexture("assets/textures/nibbler/corner0.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::LEFT && _prevDirection[i] == Direction::UP) {
            _renderer->loadTexture("assets/textures/nibbler/corner0.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::LEFT && _prevDirection[i] == Direction::DOWN) {
            _renderer->loadTexture("assets/textures/nibbler/corner3.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::RIGHT && _prevDirection[i] == Direction::UP) {
            _renderer->loadTexture("assets/textures/nibbler/corner3.png", body_string_corner);
        } else if (_prevDirection[i - 1] == Direction::RIGHT && _prevDirection[i] == Direction::DOWN) {
            _renderer->loadTexture("assets/textures/nibbler/corner0.png", body_string_corner);
        } else {
            _renderer->loadTexture("assets/textures/nibbler/body.png", body_string_corner);
        }
        switch (_prevDirection[i - 2]) {
            case Direction::UP:
                if (_mapPositionBody[i].first == 0) {
                    _mapPositionBody[i].first = 16;
                } else {
                    _mapPositionBody[i].first--;
                }
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 180);
                break;
            case Direction::DOWN:
                if (_mapPositionBody[i].first == 16) {
                    _mapPositionBody[i].first = 0;
                } else {
                    _mapPositionBody[i].first++;
                }
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 0);
                break;
            case Direction::LEFT:
                if (_mapPositionBody[i].second == 0) {
                    _mapPositionBody[i].second = 16;
                } else {
                    _mapPositionBody[i].second--;
                }
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 90);
                break;
            case Direction::RIGHT:
                if (_mapPositionBody[i].second == 16) {
                    _mapPositionBody[i].second = 0;
                } else {
                    _mapPositionBody[i].second++;
                }
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 270);
                break;
            default:
                break;
        }
    }
}

void Arcade::Nibbler::moveSnake()
{
    if (_direction == Direction::UP && _prevDirection[0] == Direction::RIGHT) {
        _renderer->loadTexture("assets/textures/nibbler/corner0.png", "body2");
    } else if (_direction == Direction::UP && _prevDirection[0] == Direction::LEFT) {
        _renderer->loadTexture("assets/textures/nibbler/corner3.png", "body2");
    } else if (_direction == Direction::DOWN && _prevDirection[0] == Direction::RIGHT) {
        _renderer->loadTexture("assets/textures/nibbler/corner3.png", "body2");
    } else if (_direction == Direction::DOWN && _prevDirection[0] == Direction::LEFT) {
        _renderer->loadTexture("assets/textures/nibbler/corner0.png", "body2");
    } else if (_direction == Direction::LEFT && _prevDirection[0] == Direction::UP) {
        _renderer->loadTexture("assets/textures/nibbler/corner0.png", "body2");
    } else if (_direction == Direction::LEFT && _prevDirection[0] == Direction::DOWN) {
        _renderer->loadTexture("assets/textures/nibbler/corner3.png", "body2");
    } else if (_direction == Direction::RIGHT && _prevDirection[0] == Direction::UP) {
        _renderer->loadTexture("assets/textures/nibbler/corner3.png", "body2");
    } else if (_direction == Direction::RIGHT && _prevDirection[0] == Direction::DOWN) {
        _renderer->loadTexture("assets/textures/nibbler/corner0.png", "body2");
    } else {
        _renderer->loadTexture("assets/textures/nibbler/body.png", "body2");
    }
    switch (_direction) {
        case Direction::UP:
            _mapPosition.first--;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 270);
            break;
        case Direction::DOWN:
            _mapPosition.first++;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 90);
            break;
        case Direction::LEFT:
            _mapPosition.second--;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 180);
            break;
        case Direction::RIGHT:
            _mapPosition.second++;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 0);
            break;
        default:
            break;
    }
}
