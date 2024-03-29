/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Snake.hpp"

void Arcade::Snake::start(std::reference_wrapper<IRenderer> renderer)
{
    _renderer = &renderer.get();

    if (!_renderer->loadTexture("assets/textures/background_snake.png", "background_snake"))
        throw std::runtime_error("Could not load texture background_snake");
    _renderer->createSprite("background_snake", 0, 0, 1, 1);
}

void Arcade::Snake::displayGame()
{
    _renderer->displaySprite("background_snake");
}