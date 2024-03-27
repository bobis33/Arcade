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

Arcade::GameEvent Arcade::SfmlRenderer::keyboardEvent(sf::Event event)
{
    switch (event.key.code) {
        case sf::Keyboard::Left:
            return Arcade::GameEvent::LEFT;
        case sf::Keyboard::Right:
            return Arcade::GameEvent::RIGHT;
        case sf::Keyboard::Up:
            return Arcade::GameEvent::UP;
        case sf::Keyboard::Down:
            return Arcade::GameEvent::DOWN;
        case sf::Keyboard::Escape:
            return Arcade::GameEvent::PAUSE;
        case sf::Keyboard::Unknown:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F1:
            return Arcade::GameEvent::SWITCH_GRAPHIC;


        default:
            return Arcade::GameEvent::NONE;
    }
}

Arcade::GameEvent Arcade::SfmlRenderer::getEvent()
{
    sf::Event event{};

    while (_window.getWindow()->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                return keyboardEvent(event);
            case sf::Event::Closed:
                return Arcade::GameEvent::QUIT;

            default:
                return Arcade::GameEvent::NONE;
        }
    }
    return Arcade::GameEvent::NONE;
}
