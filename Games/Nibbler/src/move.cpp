/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** move
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::setDirection(const Direction &dir)
{
    if (dir == Direction::UP && _direction != Direction::DOWN && _mapPositionWall[_mapPosition.first - 1][_mapPosition.second] != 'X' && _mapPosition.first != 0)
        _direction = dir;
    else if (dir == Direction::DOWN && _direction != Direction::UP && _mapPositionWall[_mapPosition.first + 1][_mapPosition.second] != 'X' && _mapPosition.first != 16)
        _direction = dir;
    else if (dir == Direction::LEFT && _direction != Direction::RIGHT && _mapPositionWall[_mapPosition.first][_mapPosition.second - 1] != 'X' && _mapPosition.second != 0)
        _direction = dir;
    else if (dir == Direction::RIGHT && _direction != Direction::LEFT && _mapPositionWall[_mapPosition.first][_mapPosition.second + 1] != 'X' && _mapPosition.second != 16)
        _direction = dir;
}

void Arcade::Nibbler::checkIfCanMove(std::pair<size_t, size_t> pos, Direction dir)
{
    if (dir == Direction::UP) {
        if (pos.first == 0 || _mapPositionWall[pos.first - 1][pos.second] == 'X')
            _canMove = false;
        else
            _canMove = true;
    } else if (dir == Direction::DOWN) {
        if (pos.first == 16 || _mapPositionWall[pos.first + 1][pos.second] == 'X')
            _canMove = false;
        else
            _canMove = true;
    } else if (dir == Direction::LEFT) {
        if (pos.second == 0 || _mapPositionWall[pos.first][pos.second - 1] == 'X')
            _canMove = false;
        else
            _canMove = true;
    } else if (dir == Direction::RIGHT) {
        if (pos.second == 16 || _mapPositionWall[pos.first][pos.second + 1] == 'X')
            _canMove = false;
        else
            _canMove = true;
    }
}

void Arcade::Nibbler::moveBody()
{
    std::string body_string{"body"};
    for (size_t i = 1; i <= _snakeSize; i++) {
        body_string = "body";
        body_string += std::to_string(i);
        switch (_prevDirection[i - 2]) {
            case Direction::UP:
                if (_mapPositionBody[i].first == 0)
                    _mapPositionBody[i].first = 16;
                else
                    _mapPositionBody[i].first--;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 180);
                break;
            case Direction::DOWN:
                if (_mapPositionBody[i].first == 16)
                    _mapPositionBody[i].first = 0;
                else
                    _mapPositionBody[i].first++;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 0);
                break;
            case Direction::LEFT:
                if (_mapPositionBody[i].second == 0)
                    _mapPositionBody[i].second = 16;
                else
                    _mapPositionBody[i].second--;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 90);
                break;
            case Direction::RIGHT:
                if (_mapPositionBody[i].second == 16)
                    _mapPositionBody[i].second = 0;
                else
                    _mapPositionBody[i].second++;
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
