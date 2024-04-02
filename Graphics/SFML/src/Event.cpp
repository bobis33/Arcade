/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/SfmlRenderer.hpp"

Arcade::KeyboardEvents Arcade::SfmlRenderer::keyboardEvent(const sf::Event &event)
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

void Arcade::SfmlRenderer::setInput(const sf::Event &event) {
    if (event.text.unicode < 128) {
        if (event.text.unicode == 8 && _input.size() > 0) {
            _input.pop_back();
        } else if (event.text.unicode != 8) {
            _input += static_cast<char>(event.text.unicode);
        }
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
            case sf::Event::TextEntered:
                    setInput(event);
                return Arcade::KeyboardEvents::TEXTENTERED;

            default:
                return Arcade::KeyboardEvents::NONE;
        }
    }
    return Arcade::KeyboardEvents::NONE;
}
