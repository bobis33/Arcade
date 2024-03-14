/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

Arcade::Sfml::Sfml() : _window(sf::VideoMode(1920, 1080), "SFML window")
{
}

Arcade::GameEvent Arcade::Sfml::getEvent()
{
    sf::Event event{};
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _event = Arcade::GameEvent::QUIT;
            _window.close();
            return _event;
        }
    }
    return _event;
}

/*


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
*/