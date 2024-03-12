/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

void Arcade::Sfml::openWindow()
{
    _window.create(sf::VideoMode(1920, 1080),
                   "Arcade - SFML",
                   sf::Style::Resize |
                   sf::Style::Close |
                   sf::Style::Fullscreen);
}

void Arcade::Sfml::closeWindow()
{
    _window.close();
}

void Arcade::Sfml::clearWindow()
{
    _window.clear(sf::Color::Black);
}

void Arcade::Sfml::displayWindow()
{
    _window.display();
}
