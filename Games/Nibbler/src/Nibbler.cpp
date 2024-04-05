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

void Arcade::Nibbler::createMap()
{
    _map.clear();
    _map.resize(MAP_HEIGHT);
    for (size_t i = 0; i < MAP_HEIGHT; ++i) {
        _map[i].resize(MAP_WIDTH);
        for (size_t j = 0; j < MAP_WIDTH; ++j) {
            _map[i][j] = {(SIZE_BOX * j) + SIZE_BOX, (SIZE_BOX * i) + SIZE_BOX};
        }
    }
}

void Arcade::Nibbler::placeFood()
{
    size_t indexFood = 0;
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            if (_mapPositionWall[i][j] == 'o') {
                _mapPositionFood.push_back({{i, j}, true});
                indexFood++;
            }
        }
    }
    _nbFood = indexFood;
    std::string FoodString;
    for (size_t i = 0; i <= _nbFood; i++) {
        FoodString = "Sugar";
        FoodString += std::to_string(i);
        if (!_renderer->loadTexture("assets/textures/nibbler/sugar.png", FoodString))
            throw std::runtime_error("Could not load texture sugar");
        _renderer->createSprite(FoodString, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].first, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].second, 1, 1);
    }
}

void Arcade::Nibbler::createWall()
{
    _mapPositionWall.clear();
    _mapPositionWall = {
        {' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' '},
        {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
        {'o', 'X', ' ', 'X', 'o', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'o', 'X', ' ', 'X', 'o'},
        {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', 'X', 'o', 'X', ' ', 'X', 'o', 'X', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
        {'o', 'X', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', 'X', 'o'},
        {' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'o', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' '},
        {' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' '},
        {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
        {' ', ' ', 'o', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'o', ' ', ' '},
        {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
        {' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', 'o', ' ', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
        {'o', 'X', 'X', 'X', 'o', 'X', 'o', 'X', 'X', 'X', 'o', 'X', 'o', 'X', 'X', 'X', 'o'},
        {'o', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'o'},
        {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

std::pair<size_t, size_t> Arcade::Nibbler::getBodyPosition()
{
    std::pair<unsigned long, unsigned long> bodyPosition = _mapPosition;

    for (size_t i = 0; i < _snakeSize - 1; i++) {
        switch (_prevDirection[i]) {
            case Direction::UP:
                bodyPosition.first++;
                break;
            case Direction::DOWN:
                bodyPosition.first--;
                break;
            case Direction::LEFT:
                bodyPosition.second++;
                break;
            case Direction::RIGHT:
                bodyPosition.second--;
                break;
            default:
                break;
        }
    }
    return bodyPosition;
}

void Arcade::Nibbler::displayFood()
{
    std::string FoodString;
    for (size_t i = 0; i <= _nbFood; i++) {
        if (_mapPositionFood[i].second == true) {
            FoodString = "Sugar";
            FoodString += std::to_string(i);
            _renderer->displaySprite(FoodString);
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
    if (_userName.empty())
        _userName = "error";
    createMap();
    createWall();
    placeFood();
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

    _renderer->createText("menu_i", "Player:", SIZE_TITLE, BILLBOARD_POSITION, SIZE_BOX);
    _renderer->createText("menu_i", _userName, SIZE_TEXT, BILLBOARD_POSITION, 150);
    _renderer->createText("menu_i", "Score:", SIZE_TITLE, BILLBOARD_POSITION, 300);
    _renderer->createText("menu_i", std::to_string(_score), SIZE_TEXT, BILLBOARD_POSITION, 350);
    _renderer->createText("menu_i", "Press F2 to go back to the menu", 15, BILLBOARD_POSITION, 970);
    _renderer->createText("menu_i", "Game Over", 80, 600, 400);
}
