/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Arcade/Sfml.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SFML";

Arcade::Sfml::Sfml() {}

void Arcade::Sfml::initMenu() {
    _sprite.setTexture(_textures["background"]);
    _text.setFont(_fonts["menu_i"]);
    _text.setString("MENU");
    _text.setCharacterSize(50);
    _text.setFillColor(sf::Color::White);
    //_text.setPosition(static_cast<float>(_width / 2 - 100), static_cast<float>(_height / 2 - 100));
    _text.setPosition(static_cast<float>(1920 / 2 - 100), static_cast<float>(1080 / 2 - 100));
}

bool Arcade::Sfml::loadFont(const std::string &filePath, const std::string &name) {
    if (!_fonts[name].loadFromFile(filePath))
        return false;
    return true;
}

bool Arcade::Sfml::loadTexture(const std::string &filePath, const std::string &name) {
    if (!_textures[name].loadFromFile(filePath))
        return false;
    return true;
}

void Arcade::Sfml::displayMenu()
{
    _window.draw(_sprite);
    _window.draw(_text);
}

void Arcade::Sfml::openWindow(const unsigned int width, const unsigned int height) {
    _width = width;
    _height = height;
    _window.create(sf::VideoMode(width, height), WINDOW_TITLE.data());
    _window.setFramerateLimit(200);
}
