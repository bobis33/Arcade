/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** login.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

void Arcade::Core::displayLoginScreen()
{
    _renderer->getWindow()->clearWindow();
    _renderer->displayText("Enter your username:");
    _renderer->displayText(" ");
}

void Arcade::Core::loadLogin()
{
    if (_renderer->isASCII()) {
        _renderer->createText("menu_i", "Enter your username:", 0, 2, 2);
        _renderer->createText("menu_i", " ", 0, 3, 2);
    } else {
        _renderer->createText("menu_i", "Enter your username:", 30, WIDTH / 4, (HEIGHT / 3) - 50);
        _renderer->createText("menu_i", " ", 30, WIDTH / 4, HEIGHT / 3);
    }
}
