/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

Arcade::GameEvent Arcade::Sfml::getEvent()
{
    sf::Event event{};

    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                return Arcade::GameEvent::QUIT;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Unknown:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Escape:
                        return Arcade::GameEvent::PAUSE;
                    case sf::Keyboard::Menu:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Space:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Enter:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Backspace:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Tab:
                        return Arcade::GameEvent::NONE;
                    case sf::Keyboard::Left:
                        return Arcade::GameEvent::LEFT;
                    case sf::Keyboard::Right:
                        return Arcade::GameEvent::RIGHT;
                    case sf::Keyboard::Up:
                        return Arcade::GameEvent::UP;
                    case sf::Keyboard::Down:
                        return Arcade::GameEvent::DOWN;

                    default:
                        return Arcade::GameEvent::NONE;
                }

            default:
                return Arcade::GameEvent::NONE;
        }
    }
    return Arcade::GameEvent::NONE;
}
