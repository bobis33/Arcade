/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** move.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::moveBody()
{
    std::string body_string{"body"};

    for (size_t i = 1; i <= _snakeSize; i++) {
        body_string = "body";
        body_string += std::to_string(i);
        switch (_prevDirection[i - 2]) {
            case Direction::UP:
                if (_mapPositionBody[i].first == 0)
                    _mapPositionBody[i].first = 9;
                else
                    _mapPositionBody[i].first--;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 180);
                break;
            case Direction::DOWN:
                if (_mapPositionBody[i].first == 9)
                    _mapPositionBody[i].first = 0;
                else
                    _mapPositionBody[i].first++;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 0);
                break;
            case Direction::LEFT:
                if (_mapPositionBody[i].second == 0)
                    _mapPositionBody[i].second = 11;
                else
                    _mapPositionBody[i].second--;
                _renderer->moveSprite(body_string, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(body_string, 90);
                break;
            case Direction::RIGHT:
                if (_mapPositionBody[i].second == 11)
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

void Arcade::Snake::moveSnake()
{
    switch (_direction) {
        case Direction::UP:
            if (_mapPosition.first == 0)
                _mapPosition.first = 9;
            else
                _mapPosition.first--;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 270);
            break;
        case Direction::DOWN:
            if (_mapPosition.first == 9)
                _mapPosition.first = 0;
            else
                _mapPosition.first++;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 90);
            break;
        case Direction::LEFT:
            if (_mapPosition.second == 0)
                _mapPosition.second = 11;
            else
                _mapPosition.second--;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 180);
            break;
        case Direction::RIGHT:
            if (_mapPosition.second == 11)
                _mapPosition.second = 0;
            else
                _mapPosition.second++;
            _renderer->moveSprite("head", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head", 0);
            break;
        default:
            break;
    }
}
