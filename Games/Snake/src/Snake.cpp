/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Snake.hpp"

static constexpr int MAP_WIDTH = 12;
static constexpr int MAP_HEIGHT = 10;

static constexpr int SIZE_BOX = 90;
static constexpr int NB_MOVES = 120;
static constexpr int MOVE_SPEED = 600;

static constexpr int BILLBOARD_POSITION = 1350;
static constexpr int SIZE_TITLE = 40;
static constexpr int SIZE_TEXT = 30;

void Arcade::Snake::checkLose()
{
    for (size_t i = 1; i <= _snakeSize; i++) {
        if (_mapPosition.first == _mapPositionBody[i].first && _mapPosition.second == _mapPositionBody[i].second) {
            _clock.pause();
        }
    }
}

void Arcade::Snake::createMap()
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

void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("Sugar");
    _renderer->displaySprite("head");
    _renderer->displayText("Player:");
    _renderer->displayText(_userName);
    _renderer->displayText("Score:");
    _renderer->displayText(std::to_string(_score));
    displaySnake();

    if (_clock.getElapsedTime().asMilliseconds() < _lastMilliseconds)
        return;

    _lastMilliseconds += MOVE_SPEED;
    moveSnake();
    moveBody();
    checkLose();
    for (size_t i = NB_MOVES; i > 0; i--)
        _prevDirection[i] = _prevDirection[i - 1];

    _prevDirection[0] = _direction;
    isEating();
}

void Arcade::Snake::loadGame()
{
    _userName = _renderer->getUserName();
    createMap();

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

    _mapPositionBody.resize(NB_MOVES);
    _prevDirection.resize(NB_MOVES);
}
