/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SfmlRenderer.cpp
*/

#include "Arcade/SfmlWindow.hpp"

static constexpr std::string_view WINDOW_TITLE = "Arcade - SFML";

void Arcade::SfmlWindow::openWindow(const unsigned int width, const unsigned int height) {
    _width = width;
    _height = height;
    _window.create(sf::VideoMode(width, height), WINDOW_TITLE.data());
    _window.setFramerateLimit(200);
}
