/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text.cpp
*/


#include "Arcade/Sfml.hpp"


bool Arcade::Sfml::loadFont(const std::string &filePath, const std::string &name) {
    return _fonts[name].loadFromFile(filePath);
}

void Arcade::Sfml::createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) {
    _texts[text].setFont(_fonts[fontName]);
    _texts[text].setString(text);
    _texts[text].setCharacterSize(static_cast<unsigned int>(size));
    _texts[text].setFillColor(sf::Color::White);
    _texts[text].setPosition(pos_x, pos_y);
}

void Arcade::Sfml::displayText(const std::string &textName) {
    _window.draw(_texts[textName]);
}

