/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Snake.hpp"

static constexpr float SNAKE_BODY_SIZE = 100;

void Arcade::Snake::createMap()
{
    _map = new std::pair<float, float>*[10];
    for (int i = 0; i < 10; i++) {
        _map[i] = new std::pair<float, float>[12];
        for (int j = 0; j < 12; j++) {
            _map[i][j] = {0, 0};
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 12; ++j) {
            _map[i][j] = {(90 * j) + 90, (90 * i) + 90};
        }
    }
}

void Arcade::Snake::loadGame()
{
    createMap();

    if (!_renderer->loadTexture("assets/textures/background_snake.png", "background_snake"))
        throw std::runtime_error("Could not load texture background_snake");
    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    if (!_renderer->loadTexture("assets/textures/snake/head_right.png", "head_right"))
        throw std::runtime_error("Could not load texture head_right");
    _renderer->createSprite("head_right", _map[0][0].first, _map[0][0].second, 1, 1);
    if (!_renderer->loadTexture("assets/textures/snake/sucre.png", "Apple"))
        throw std::runtime_error("Could not load texture Apple");
    _renderer->createSprite("Apple", _map[2][2].first, _map[2][2].second, 1, 1);

    _prevDirection = new Direction[120];
    for (int i = 0; i < 120; i++) {
        _prevDirection[i] = Direction::NONE;
    }
    _mapPositionBody = new std::pair<int, int>[120];
    for (int i = 0; i < 120; i++) {
        _mapPositionBody[i] = {0, 0};
    }
}

void Arcade::Snake::replace_apple()
{
    _mapPositionApple.first = rand() % 10;
    _mapPositionApple.second = rand() % 12;
    _renderer->moveSprite("Apple", _map[_mapPositionApple.first][_mapPositionApple.second].first, _map[_mapPositionApple.first][_mapPositionApple.second].second);
}

std::string directionToString(Arcade::Direction dir) {
    switch (dir) {
        case Arcade::Direction::UP:
            return "UP";
        case Arcade::Direction::DOWN:
            return "DOWN";
        case Arcade::Direction::LEFT:
            return "LEFT";
        case Arcade::Direction::RIGHT:
            return "RIGHT";
        default:
            return "UNKNOWN";
    }
}

std::pair<int, int> Arcade::Snake::findWherePlaceBody()
{
    std::pair<int, int> headPosition = _mapPosition;
    std::pair<int, int> bodyPosition = {0, 0};
    int snakeSize = getSnakeSize();

    for (int i = 0; i < snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                bodyPosition.first = headPosition.first + 1;
                bodyPosition.second = headPosition.second;
                break;
            case Direction::DOWN:
                bodyPosition.first = headPosition.first - 1;
                bodyPosition.second = headPosition.second;
                break;
            case Direction::LEFT:
                bodyPosition.first = headPosition.first;
                bodyPosition.second = headPosition.second + 1;
                break;
            case Direction::RIGHT:
                bodyPosition.first = headPosition.first;
                bodyPosition.second = headPosition.second - 1;
                break;
            default:
                break;
        }
        headPosition = bodyPosition;
    }
    return bodyPosition;
}


void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("head_right");
    _renderer->displaySprite("Apple");
    if (_snakeSize > 1)
        for (int i = 1; i <= _snakeSize; i++) {
            std::string bodystring = "body";
            bodystring += std::to_string(i);
            _renderer->displaySprite(bodystring);
        }

    if (_clock.getElapsedTime().asSeconds() > _lastSecond) {
        _lastSecond++;
        moveSnake("head_right");
        moveBody();
        _nbMoves++;
        for (int i = 120; i > 0; i--) {
            _prevDirection[i] = _prevDirection[i - 1];
        }
        _prevDirection[0] = _direction;
        if (_mapPosition.first == _mapPositionApple.first && _mapPosition.second == _mapPositionApple.second) {
            _snakeSize++;
            std::string bodystring = "body";
            bodystring += std::to_string(_snakeSize);
            if (!_renderer->loadTexture("assets/textures/snake/body_horizontal.png", bodystring))
                throw std::runtime_error("Could not load texture body2");
            std::pair<int, int> bodyPosition = findWherePlaceBody();
            _mapPositionBody[_snakeSize] = bodyPosition;
            _renderer->createSprite(bodystring, _map[bodyPosition.first][bodyPosition.second].first, _map[bodyPosition.first][bodyPosition.second].second, 1, 1);
            replace_apple();
        }
    }
}

void Arcade::Snake::moveBody()
{
    for (int i = 1; i <= _snakeSize; i++) {
        std::string bodystring = "body";
        bodystring += std::to_string(i);
        switch (_prevDirection[i - 2]) {
            case Direction::UP:
                if (_mapPositionBody[i].first == 0)
                    _mapPositionBody[i].first = 9;
                else
                    _mapPositionBody[i].first--;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                break;
            case Direction::DOWN:
                if (_mapPositionBody[i].first == 9)
                    _mapPositionBody[i].first = 0;
                else
                    _mapPositionBody[i].first++;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                break;
            case Direction::LEFT:
                if (_mapPositionBody[i].second == 0)
                    _mapPositionBody[i].second = 11;
                else
                    _mapPositionBody[i].second--;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                break;
            case Direction::RIGHT:
                if (_mapPositionBody[i].second == 11)
                    _mapPositionBody[i].second = 0;
                else
                    _mapPositionBody[i].second++;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                break;
            default:
                break;
        }
    }
}

void Arcade::Snake::moveSnake(std::string snakePart)
{
    switch (_direction) {
        case Direction::UP:
            if (_mapPosition.first == 0)
                _mapPosition.first = 9;
            else
                _mapPosition.first--;
            _renderer->moveSprite(snakePart, _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite(snakePart, 270);
            break;
        case Direction::DOWN:
            if (_mapPosition.first == 9)
                _mapPosition.first = 0;
            else
                _mapPosition.first++;
            _renderer->moveSprite(snakePart, _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite(snakePart, 90);
            break;
        case Direction::LEFT:
            if (_mapPosition.second == 0)
                _mapPosition.second = 11;
            else
                _mapPosition.second--;
            _renderer->moveSprite(snakePart, _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite(snakePart, 180);
            break;
        case Direction::RIGHT:
            if (_mapPosition.second == 11)
                _mapPosition.second = 0;
            else
                _mapPosition.second++;
            _renderer->moveSprite(snakePart, _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite(snakePart, 0);
            break;
        default:
            break;
    }
}
