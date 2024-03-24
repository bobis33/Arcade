/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Arcade/Sfml.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SFML";

Arcade::Sfml::Sfml() {
    // to move in menu
    if (!loadFont("assets/fonts/menu_i.ttf", "menu_i")) {
        throw std::runtime_error("Cannot load fonts");
    }
    if (!loadTexture("assets/textures/background.jpg", "background")) {
        throw std::runtime_error("Cannot load background texture");
    }
    _sprite.setTexture(_textures["background"]);
    _text.setFont(_fonts["menu_i"]);
    _text.setString("MENU");
    _text.setCharacterSize(50);
    _text.setFillColor(sf::Color::White);
    //_text.setPosition(static_cast<float>(_width / 2 - 100), static_cast<float>(_height / 2 - 100));
    _text.setPosition(static_cast<float>(1920 / 2 - 100), static_cast<float>(1080 / 2 - 100));

}

bool Arcade::Sfml::loadFont(const std::string &filePath, const std::string &name) {
    sf::Font font;

    if (!font.loadFromFile(filePath)) {
        return false;
    }
    _fonts[name] = font;
    return true;
}

bool Arcade::Sfml::loadTexture(const std::string &filePath, const std::string &name) {
    sf::Texture texture;

    if (!texture.loadFromFile(filePath)) {
        return false;
    }
    _textures[name] = texture;
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
