/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu.cpp
*/

#include "Arcade/RuntimeException.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::displayMenu() {
    _renderer->displaySprite("background");
    _renderer->displayText("MENU");
    for (const auto & graphicLibrarie : _graphicLibs) {
        _renderer->displayText(graphicLibrarie);
    }
    for (const auto & gameLibrarie : _gameLibs) {
        _renderer->displayText(gameLibrarie);
    }
    _renderer->displayText(">");
}

void Arcade::Core::loadMenu() {
    if (_renderer->isASCII()) {
        //loadTextures(someasciiartonlyformenu, "ascii art name");
    } else {
        if (!_renderer->loadFont("assets/fonts/menu_i.ttf", "menu_i")) {
            throw RuntimeException("Cannot load fonts");
        } if (!_renderer->loadTexture("assets/textures/background.jpg", "background")) {
            throw RuntimeException("Cannot load background texture");
        }
        _renderer->createSprite("background", 0, 0, 1, 1);
        _renderer->createText("menu_i", "MENU", 50, WIDTH / 2 - 100, HEIGHT / 12);
        _renderer->createText("menu_i", ">", 50, static_cast<float>(WIDTH * 0.07), static_cast<float>(HEIGHT / 2 - 110 + 50 * (0 + 1)));
        for (unsigned int index = 0; index < _graphicLibs.size(); index++) {
            _renderer->createText("menu_i", _graphicLibs[index], 30, WIDTH * 0.6, (static_cast<float>(HEIGHT / 2 - 100 + 50 * (index + 1))));
        }
        for (unsigned int index = 0; index < _gameLibs.size(); index++) {
            _renderer->createText("menu_i", _gameLibs[index], 30, WIDTH * 0.1, (static_cast<float>(HEIGHT / 2 - 100 + 50 * (index + 1))));
        }
        _renderer->loadSound();
    }
}
