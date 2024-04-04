/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::loadGame()
{
    if (_userName.empty())
        _userName = "error";

    if (!_renderer->loadTexture("assets/textures/snake/head.png", "head")) {
        throw std::runtime_error("Could not load texture head");
    } if (!_renderer->loadTexture("assets/textures/snake/sugar.png", "Sugar")) {
        throw std::runtime_error("Could not load texture Sugar");
    }

    _renderer->createSprite("Sugar", 100, 100, 1, 1);

    _renderer->createText("menu_i", "Player:", SIZE_TITLE, BILLBOARD_POSITION, 90);
    _renderer->createText("menu_i", _userName, SIZE_TEXT, BILLBOARD_POSITION, 150);
    _renderer->createText("menu_i", "Score:", SIZE_TITLE, BILLBOARD_POSITION, 300);
    _renderer->createText("menu_i", std::to_string(_score), SIZE_TEXT, BILLBOARD_POSITION, 350);
    _renderer->createText("menu_i", "Press F2 to go back to the menu", 15, BILLBOARD_POSITION, 970);
    _renderer->createText("menu_i", "Game Over", 80, 600, 400);
}

