/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Arcade/Sfml.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SFML";

void Arcade::Sfml::openWindow(const unsigned int width, const unsigned int height) {
    _width = width;
    _height = height;
    _window.create(sf::VideoMode(width, height), WINDOW_TITLE.data());
    _window.setFramerateLimit(200);
}
