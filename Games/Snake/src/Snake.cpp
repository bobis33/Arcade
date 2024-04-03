/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include <random>
#include "Arcade/Snake.hpp"

static constexpr int MAP_WIDTH = 12;
static constexpr int MAP_HEIGHT = 10;
static constexpr int NB_MOVES = 120;

static constexpr int MOVE_SPEED = 600;

void Arcade::Snake::checkLose()
{
    for (int i = 1; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
        }
    }
}

void Arcade::Snake::createMap()
{
    _map = new std::pair<float, float>*[MAP_HEIGHT];
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        _map[i] = new std::pair<float, float>[MAP_WIDTH];
        for (int j = 0; j < MAP_WIDTH; ++j) {
            _map[i][j] = {(90 * j) + 90, (90 * i) + 90};
        }
    }
}

void Arcade::Snake::loadGame()
{
    createMap();
    _renderer->createText("menu_i", "Score: ", 40, 1500, 100);
    if (!_renderer->loadTexture("assets/textures/background_snake.png", "background_snake"))
        throw std::runtime_error("Could not load texture background_snake");
    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    if (!_renderer->loadTexture("assets/textures/snake/head.png", "head"))
        throw std::runtime_error("Could not load texture head");
    _renderer->createSprite("head", _map[0][0].first, _map[0][0].second, 1, 1);
    if (!_renderer->loadTexture("assets/textures/snake/sugar.png", "Sugar"))
        throw std::runtime_error("Could not load texture Sugar");
    _renderer->createSprite("Sugar", _map[2][2].first, _map[2][2].second, 1, 1);

    _prevDirection = new Direction[NB_MOVES];
    _mapPositionBody = new std::pair<int, int>[NB_MOVES];
    for (int i = 0; i < NB_MOVES; i++) {
        _prevDirection[i] = Direction::NONE;
        _mapPositionBody[i] = {0, 0};
    }
}

void Arcade::Snake::replaceFood()
{
    bool isOnSnake = true;
    std::random_device rd{};
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> x(0, 9);
    std::uniform_int_distribution<> y(0, 11);

    while (isOnSnake) {
        isOnSnake = false;
        _mapPositionFood = {x(gen), y(gen)};
        for (int i = 0; i < _snakeSize + 2; i++) {
            if (_mapPositionFood.first == _mapPositionBody[i].first && _mapPositionFood.second == _mapPositionBody[i].second) {
                isOnSnake = true;
                break;
            }
        }
    }
    _renderer->moveSprite("Sugar", _map[_mapPositionFood.first][_mapPositionFood.second].first, _map[_mapPositionFood.first][_mapPositionFood.second].second);
}

std::pair<int, int> Arcade::Snake::getBodyPosition()
{
    std::pair<int, int> bodyPosition = _mapPosition;

    for (int i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                if (bodyPosition.first == 9)
                    bodyPosition.first = 0;
                else
                    bodyPosition.first++;
                break;
            case Direction::DOWN:
                if (bodyPosition.first == 0)
                    bodyPosition.first = 9;
                else
                    bodyPosition.first--;
                break;
            case Direction::LEFT:
                if (bodyPosition.second == 11)
                    bodyPosition.second = 0;
                else
                    bodyPosition.second++;
                break;
            case Direction::RIGHT:
                if (bodyPosition.second == 0)
                    bodyPosition.second = 11;
                else
                    bodyPosition.second--;
                break;
            default:
                break;
        }
    }
    return bodyPosition;
}

void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("head");
    _renderer->displaySprite("Sugar");
    _renderer->displayText("Score: ");
    if (_snakeSize > 1)
        for (int i = 1; i <= _snakeSize; i++) {
            std::string bodystring = "body";
            bodystring += std::to_string(i);
            _renderer->displaySprite(bodystring);
        }

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += MOVE_SPEED;
    moveSnake("head");
    moveBody();
    checkLose();
    _nbMoves++;
    for (int i = NB_MOVES; i > 0; i--) {
        _prevDirection[i] = _prevDirection[i - 1];
    }
    _prevDirection[0] = _direction;
    if (_mapPosition.first == _mapPositionFood.first && _mapPosition.second == _mapPositionFood.second) {
        _snakeSize++;
        std::string bodystring{"body"};
        bodystring += std::to_string(_snakeSize);
        if (!_renderer->loadTexture("assets/textures/snake/body.png", bodystring))
            throw std::runtime_error("Could not load texture body");
        std::pair<int, int> bodyPosition = getBodyPosition();
        _mapPositionBody[_snakeSize] = bodyPosition;
        _renderer->createSprite(bodystring, _map[bodyPosition.first][bodyPosition.second].first, _map[bodyPosition.first][bodyPosition.second].second, 1, 1);
        replaceFood();
    }
}

void Arcade::Snake::moveBody()
{
    for (int i = 1; i <= _snakeSize; i++) {
        std::string bodystring{"body"};
        bodystring += std::to_string(i);
        switch (_prevDirection[i - 2]) {
            case Direction::UP:
                if (_mapPositionBody[i].first == 0)
                    _mapPositionBody[i].first = 9;
                else
                    _mapPositionBody[i].first--;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(bodystring, 180);
                break;
            case Direction::DOWN:
                if (_mapPositionBody[i].first == 9)
                    _mapPositionBody[i].first = 0;
                else
                    _mapPositionBody[i].first++;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(bodystring, 0);
                break;
            case Direction::LEFT:
                if (_mapPositionBody[i].second == 0)
                    _mapPositionBody[i].second = 11;
                else
                    _mapPositionBody[i].second--;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(bodystring, 90);
                break;
            case Direction::RIGHT:
                if (_mapPositionBody[i].second == 11)
                    _mapPositionBody[i].second = 0;
                else
                    _mapPositionBody[i].second++;
                _renderer->moveSprite(bodystring, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].first, _map[_mapPositionBody[i].first][_mapPositionBody[i].second].second);
                _renderer->rotateSprite(bodystring, 270);
                break;
            default:
                break;
        }
    }
}

void Arcade::Snake::moveSnake(const std::string &snakePart)
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
