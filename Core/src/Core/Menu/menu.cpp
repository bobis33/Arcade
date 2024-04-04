/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu.cpp
*/

#include <cstring>
#include "Arcade/RuntimeException.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::displayMenu()
{
    _renderer->displaySprite("background");
    _renderer->displayText("MENU");
    _renderer->displayText("Welcome " + _userName);
    for (const auto & graphicLibrarie : _graphicLibs) {
        _renderer->displayText(graphicLibrarie);
    }
    for (const auto & gameLibrarie : _gameLibs) {
        _renderer->displayText(gameLibrarie);
    }
    _renderer->displayText(">");
}

void Arcade::Core::loadMenu()
{
    _currentGameIndex = 0;
    if (_renderer->isASCII()) {
        _renderer->createText("menu_i", "MENU", 0, 4, 40 - 2);
        _renderer->createText("menu_i", "Welcome " + _userName, 0, 7, static_cast<float>(40 - ((_userName.length() + 8) / 2)));
        _renderer->createText("menu_i", ">", 0, 10 + 1, 5);
        for (unsigned int index = 0; index < _gameLibs.size(); index++) {
            _renderer->createText("menu_i", _gameLibs[index], 0, static_cast<float>(10 + (index + 1)), static_cast<float>(20 - _gameLibs[index].length() / 2));
        }
        for (unsigned int index = 0; index < _graphicLibs.size(); index++) {
            _renderer->createText("menu_i", _graphicLibs[index], 0, static_cast<float>(10 + (index + 1)), static_cast<float>(60 - _graphicLibs[index].length() / 2));
        }
    } else {
        if (!_renderer->loadTexture("assets/textures/background.jpg", "background")) {
            throw RuntimeException("Cannot load background texture");
        }
        _renderer->createSprite("background", 0, 0, 1, 1);
        _renderer->createText("menu_i", "MENU", 50, WIDTH / 2 - 100, HEIGHT / 10);
        _renderer->createText("menu_i", "Welcome " + _userName, 30, WIDTH * 0.4, HEIGHT / 6);
        _renderer->createText("menu_i", ">", 50, static_cast<float>(WIDTH * 0.07), static_cast<float>(HEIGHT / 2 - 110 + 50 * (0 + 1)));
        for (unsigned int index = 0; index < _graphicLibs.size(); index++) {
            _renderer->createText("menu_i", _graphicLibs[index], 30, WIDTH * 0.6, (static_cast<float>(HEIGHT / 2 - 100 + 50 * (index + 1))));
        }
        for (unsigned int index = 0; index < _gameLibs.size(); index++) {
            _renderer->createText("menu_i", _gameLibs[index], 30, WIDTH * 0.1, (static_cast<float>(HEIGHT / 2 - 100 + 50 * (index + 1))));
        }
    }
}
