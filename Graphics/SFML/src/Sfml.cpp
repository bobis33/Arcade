/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Arcade/Sfml.hpp"

Arcade::Sfml::Sfml() : _window(sf::VideoMode(1920, 1080), WINDOW_TITLE.data()) {
    _window.setFramerateLimit(200);
    if (!_font.loadFromFile("assets/fonts/menu_i.ttf"))
        throw std::runtime_error("Cannot load fonts");
    if (!_texture.loadFromFile("assets/images/bg.jpg"))
        throw std::runtime_error("Cannot load background texture");
    _sprite.setTexture(_texture);
    _text.setFont(_font);
    _text.setString("MENU");
    _text.setCharacterSize(50);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(1920 / 2 - 100, 1080 / 2 - 100);
    _text.setPosition(50, 200);
}

void Arcade::Sfml::displayMenu()
{
    _window.draw(_sprite);
    _window.draw(_text);
}
