/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/SfmlRenderer.hpp"

/*
 * push on the top of the switch cases that will be the most used (and who's implemented too)
 * for optimisation. For example if u put an event at the end of the switch, in every case
 * the program will do the whole switch to reach the last case.
*/

Arcade::KeyboardEvents Arcade::SfmlRenderer::keyboardEvent(sf::Event event)
{
    switch (event.key.code) {
        case sf::Keyboard::Left:
            return Arcade::KeyboardEvents::LEFT;
        case sf::Keyboard::Right:
            return Arcade::KeyboardEvents::RIGHT;
        case sf::Keyboard::Up:
            return Arcade::KeyboardEvents::UP;
        case sf::Keyboard::Down:
            return Arcade::KeyboardEvents::DOWN;
        case sf::Keyboard::Escape:
            return Arcade::KeyboardEvents::ESC;
        case sf::Keyboard::Enter:
            return Arcade::KeyboardEvents::ENTER;
        case sf::Keyboard::Unknown:
            return Arcade::KeyboardEvents::NONE;
        case sf::Keyboard::F1:
            return Arcade::KeyboardEvents::F1;
        case sf::Keyboard::F2:
            return Arcade::KeyboardEvents::F2;


        default:
            return Arcade::KeyboardEvents::NONE;
    }
}

Arcade::KeyboardEvents Arcade::SfmlRenderer::getEvent()
{
    sf::Event event{};

    while (_window.getWindow()->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                return keyboardEvent(event);
            case sf::Event::Closed:
                return Arcade::KeyboardEvents::ESC;

            default:
                return Arcade::KeyboardEvents::NONE;
        }
    }
    return Arcade::KeyboardEvents::NONE;
}
