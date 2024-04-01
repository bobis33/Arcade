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
    _renderer->createSprite("Apple", _map[4][4].first, _map[4][4].second, 1, 1);
}

void Arcade::Snake::replace_apple()
{
    _mapPositionApple.first = rand() % 10;
    _mapPositionApple.second = rand() % 12;
    _renderer->moveSprite("Apple", _map[_mapPositionApple.first][_mapPositionApple.second].first, _map[_mapPositionApple.first][_mapPositionApple.second].second);
}

void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("head_right");
    _renderer->displaySprite("Apple");

    if (_clock.getElapsedTime().asSeconds() > _lastSecond) {
        _lastSecond++;
        moveSnake();
        if (_mapPosition.first == _mapPositionApple.first && _mapPosition.second == _mapPositionApple.second) {
            _snakeSize++;
            replace_apple();
        }
        printf("Snake position: %d, %d\n", _mapPosition.first, _mapPosition.second);
        printf("Apple position: %d, %d\n", _mapPositionApple.first, _mapPositionApple.second);
        printf("Snake size: %d\n", _snakeSize);
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
            _renderer->moveSprite("head_right", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second + 90);
            _renderer->rotateSprite("head_right", 270);
            break;
        case Direction::DOWN:
            if (_mapPosition.first == 9)
                _mapPosition.first = 0;
            else
                _mapPosition.first++;
            _renderer->moveSprite("head_right", _map[_mapPosition.first][_mapPosition.second].first + 90, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head_right", 90);
            break;
        case Direction::LEFT:
            if (_mapPosition.second == 0)
                _mapPosition.second = 11;
            else
                _mapPosition.second--;
            _renderer->moveSprite("head_right", _map[_mapPosition.first][_mapPosition.second].first + 90, _map[_mapPosition.first][_mapPosition.second].second + 90);
            _renderer->rotateSprite("head_right", 180);
            break;
        case Direction::RIGHT:
            if (_mapPosition.second == 11)
                _mapPosition.second = 0;
            else
                _mapPosition.second++;
            _renderer->moveSprite("head_right", _map[_mapPosition.first][_mapPosition.second].first, _map[_mapPosition.first][_mapPosition.second].second);
            _renderer->rotateSprite("head_right", 0);
            break;
        default:
            break;
    }
}
