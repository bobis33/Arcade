/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Snake.hpp"

static constexpr float SNAKE_BODY_SIZE = 100;

void Arcade::Snake::loadGame()
{
    if (!_renderer->loadTexture("assets/textures/background_snake.png", "background_snake"))
        throw std::runtime_error("Could not load texture background_snake");
    _renderer->createSprite("background_snake", 0, 0, 1, 1);
    if (!_renderer->loadTexture("assets/textures/snake/head_right.png", "head_right"))
        throw std::runtime_error("Could not load texture head_right");
    _renderer->createSprite("head_right", SNAKE_BODY_SIZE, SNAKE_BODY_SIZE, 1, 1);
}

void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
    _renderer->displaySprite("head_right");
}

void Arcade::Snake::moveSnake(float pos_x, float pos_y)
{
    _renderer->moveSprite("head_right", pos_x, pos_y);
}
