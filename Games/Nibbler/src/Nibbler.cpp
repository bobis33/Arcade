/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::checkLose()
{
    for (size_t i = 4; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
            _gameMode = GameMode::GAME_OVER;
        }
    }
}

std::pair<size_t, size_t> Arcade::Nibbler::getBodyPosition()
{
    std::pair<unsigned long, unsigned long> body_position = _mapPosition;

    for (size_t i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                body_position.first++;
                break;
            case Direction::DOWN:
                body_position.first--;
                break;
            case Direction::LEFT:
                body_position.second++;
                break;
            case Direction::RIGHT:
                body_position.second--;
                break;
            default:
                break;
        }
    }
    return body_position;
}

void Arcade::Nibbler::displayFood()
{
    std::string food_string{"Sugar"};

    for (size_t i = 0; i <= _nbFood; i++) {
        if (_mapPositionFood[i].second == true) {
            food_string = "Sugar";
            food_string += std::to_string(i);
            _renderer->displaySprite(food_string);
        }
    }
}

void Arcade::Nibbler::displaySnake()
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


void Arcade::Nibbler::loadGame()
{
    std::pair<size_t, size_t> body_position = {16, 8};
    std::string body_string{"body"};
    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
    if (_userName.empty())
        _userName = "error";

    createMap();
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
    if (!_renderer->loadTexture("assets/textures/background_nibbler.png", "background_snake")) {
        throw std::runtime_error("Could not load texture background_snake");
    } if (!_renderer->loadTexture("assets/textures/nibbler/head.png", "head")) {
        throw std::runtime_error("Could not load texture head");
    } if (!_renderer->loadTexture("assets/textures/nibbler/map1_nibbler.png", "map1")) {
        throw std::runtime_error("Could not load texture map1");
    }

    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    _renderer->createSprite("map1", 0, 0, 1, 1);
    _renderer->createSprite("head", _map[0][0].first, _map[0][0].second, 1, 1);

    _renderer->createText("menu_i", "Player:", SIZE_TITLE, BILLBOARD_POSITION, 110);
    _renderer->createText("menu_i", _userName, SIZE_TEXT, BILLBOARD_POSITION, 160);
    _renderer->createText("menu_i", "Score:", SIZE_TITLE, BILLBOARD_POSITION, 300);
    _renderer->createText("menu_i", std::to_string(_score), SIZE_TEXT, BILLBOARD_POSITION, 350);
    _renderer->createText("menu_i", "Press F2 to go back to the menu", 15, 1270, 970);
    _renderer->createText("menu_i", "Game Over", 80, 600, 400);
}
