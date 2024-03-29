/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text.cpp
*/


#include "Arcade/SfmlRenderer.hpp"

void Arcade::SfmlRenderer::moveText(const std::string &textName, int pos_x, int pos_y) {
    _texts[textName].setPosition(static_cast<float>(pos_x), static_cast<float>(pos_y));
}

bool Arcade::SfmlRenderer::loadFont(const std::string &filePath, const std::string &name) {
    return (_fonts[name].loadFromFile(filePath));
}

void Arcade::SfmlRenderer::createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) {
    _texts[text].setFont(_fonts[fontName]);
    _texts[text].setString(text);
    _texts[text].setCharacterSize(static_cast<unsigned int>(size));
    _texts[text].setFillColor(sf::Color::White);
    _texts[text].setPosition(pos_x, pos_y);
}

void Arcade::SfmlRenderer::displayText(const std::string &textName) {
    _window.getWindow()->draw(_texts[textName]);
}

