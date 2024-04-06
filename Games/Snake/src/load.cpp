/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** load.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::createMap()
{
    _map.resize(MAP_HEIGHT);
    for (size_t i = 0; i < MAP_HEIGHT; ++i) {
        _map[i].resize(MAP_WIDTH);
        for (size_t j = 0; j < MAP_WIDTH; ++j) {
            _map[i][j] = {(SIZE_BOX * j) + SIZE_BOX, (SIZE_BOX * i) + SIZE_BOX};
        }
    }
}

void Arcade::Snake::loadSnake()
{
    std::pair<size_t, size_t> bodyPosition = {5, 4};
    std::string bodyString{};
    for (size_t i = 0; i < 3; i++) {
        _prevDirection[i] = Direction::RIGHT;
        _snakeSize++;
        bodyString = "body";
        bodyString += std::to_string(_snakeSize);
        if (!_renderer->loadTexture("assets/textures/snake/body.png", bodyString))
            throw std::runtime_error("Could not load texture body");
        bodyPosition.second = 4 - i;
        _mapPositionBody[_snakeSize] = bodyPosition;
        _renderer->createSprite(bodyString, _map[bodyPosition.first][bodyPosition.second].first, _map[bodyPosition.first][bodyPosition.second].second, 1, 1);
    }
    if (!_renderer->loadTexture("assets/textures/background_snake.png", "background_snake")) {
        throw std::runtime_error("Could not load texture background_snake");
    } if (!_renderer->loadTexture("assets/textures/snake/head.png", "head")) {
        throw std::runtime_error("Could not load texture head");
    } if (!_renderer->loadTexture("assets/textures/snake/sugar.png", "Sugar")) {
        throw std::runtime_error("Could not load texture Sugar");
    }

    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    _renderer->createSprite("head", _map[0][0].first, _map[0][0].second, 1, 1);
    _renderer->createSprite("Sugar", _map[2][2].first, _map[2][2].second, 1, 1);

    _renderer->createText("menu_i", "Player:", SIZE_TITLE, BILLBOARD_POSITION, SIZE_BOX);
    _renderer->createText("menu_i", _userName, SIZE_TEXT, BILLBOARD_POSITION, 150);
    _renderer->createText("menu_i", "Score:", SIZE_TITLE, BILLBOARD_POSITION, 300);
    _renderer->createText("menu_i", std::to_string(_score), SIZE_TEXT, BILLBOARD_POSITION, 350);
    _renderer->createText("menu_i", "Press F2 to go back to the menu", 15, BILLBOARD_POSITION, 970);
    _renderer->createText("menu_i", "Game Over", 80, 600, 400);
}

void Arcade::Snake::loadAsciiSnake()
{
    _renderer->createText("0", "Player:", 0, 2, 70);
    _renderer->createText("0", _userName, 0, 3, 70);
    _renderer->createText("0", "Score:", 0, 5, 70);
    _renderer->createText("0", std::to_string(_score), 0, 6, 70);
    _renderer->createText("0", "Press F2 to go back to the menu", 0, 38, 47);
    _renderer->createText("0", "Game Over", 0, 20, 40 - 4);
}

void Arcade::Snake::loadGame()
{
    _isAscii = _renderer->isASCII();
    if (_userName.empty())
        _userName = "error";
    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
    createMap();
    if (_isAscii) {
        loadAsciiSnake();
    } else {
        loadSnake();
    }
}
