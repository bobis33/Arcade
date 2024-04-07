/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** load.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::createSnake()
{
    std::pair<size_t, size_t> body_position = {16, 8};
    std::string body_string{"body"};

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
}

void Arcade::Nibbler::loadASCIINibbler()
{
    _renderer->createText("0", "Player:", 0, 2, 70);
    _renderer->createText("0", _userName, 0, 3, 70);
    _renderer->createText("0", "Score:", 0, 5, 70);
    _renderer->createText("0", std::to_string(_score), 0, 6, 70);
    _renderer->createText("0", "Press F2 to go back to the menu", 0, 38, 47);
    _renderer->createText("0", "Game Over", 0, 20, 40 - 4);
}

void Arcade::Nibbler::loadNibbler()
{
    createSnake();
    if (!_renderer->loadTexture("assets/textures/background_nibbler.png", "background_snake")) {
        throw std::runtime_error("Could not load texture background_snake");
    } if (!_renderer->loadTexture("assets/textures/nibbler/head.png", "head")) {
        throw std::runtime_error("Could not load texture head");
    } if (!_renderer->loadTexture("assets/textures/nibbler/map1_nibbler.png", "map1")) {
        throw std::runtime_error("Could not load texture map1");
    } if (!_renderer->loadTexture("assets/textures/nibbler/map2_nibbler.png", "map2")) {
        throw std::runtime_error("Could not load texture map2");
    }

    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    _renderer->createSprite("map1", 0, 0, 1, 1);
    _renderer->createSprite("map2", 0, 0, 1, 1);
    _renderer->createSprite("head", _map[0][0].first, _map[0][0].second, 1, 1);

    _renderer->createText("menu_i", "Player:", SIZE_TITLE, BILLBOARD_POSITION, 110);
    _renderer->createText("menu_i", _userName, SIZE_TEXT, BILLBOARD_POSITION, 160);
    _renderer->createText("menu_i", "Score:", SIZE_TITLE, BILLBOARD_POSITION, 300);
    _renderer->createText("menu_i", std::to_string(_score), SIZE_TEXT, BILLBOARD_POSITION, 350);
    _renderer->createText("menu_i", "Press F2 to go back to the menu", 15, 1270, 970);
    _renderer->createText("menu_i", "Game Over", 80, 600, 400);
}

void Arcade::Nibbler::loadGame()
{
    _isAscii = _renderer->isASCII();
    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
    if (_userName.empty())
        _userName = "error";

    createMap();
    if (_isAscii) {
        loadASCIINibbler();
    }else {
        loadNibbler();
    }
}
