/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake.cpp
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::checkLose()
{
    for (size_t i = 3; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
            _gameMode = GameMode::GAME_OVER;
        }
    }
}

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

std::pair<size_t, size_t> Arcade::Snake::getBodyPosition()
{
    std::pair<unsigned long, unsigned long> bodyPosition = _mapPosition;

    for (size_t i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                if (bodyPosition.first == 9) {
                    bodyPosition.first = 0;
                } else {
                    bodyPosition.first++;
                }
                break;
            case Direction::DOWN:
                if (bodyPosition.first == 0) {
                    bodyPosition.first = 9;
                } else {
                    bodyPosition.first--;
                }
                break;
            case Direction::LEFT:
                if (bodyPosition.second == 11) {
                    bodyPosition.second = 0;
                } else {
                    bodyPosition.second++;
                }
                break;
            case Direction::RIGHT:
                if (bodyPosition.second == 0) {
                    bodyPosition.second = 11;
                } else {
                    bodyPosition.second--;
                }
                break;
            default:
                break;
        }
    }
    return bodyPosition;
}

void Arcade::Snake::displaySnake()
{
    std::string body_string{"body"};

    if (_snakeSize > 1) {
        for (size_t i = 1; i <= _snakeSize; i++) {
            body_string = "body";
            body_string += std::to_string(i);
            _renderer->displaySprite(body_string);
        }
    }
    _renderer->displaySprite("head");
}


void Arcade::Snake::loadGame()
{
    if (_userName.empty())
        _userName = "error";
    createMap();
    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
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
