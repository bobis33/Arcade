/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.cpp
*/

#include "Sfml.hpp"

/*
 * push on the top of the switch cases that will be the most used (and who's implemented too)
 * for optimisation. For example if u put an event at the end of the switch, in every case
 * the program will do the whole switch to reach the last case.
*/

Arcade::GameEvent Arcade::Sfml::keyboardEvent(sf::Event event)
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
        case sf::Keyboard::A:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::B:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::C:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::D:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::E:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::G:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::H:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::I:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::J:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::K:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::L:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::M:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::N:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::O:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::P:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Q:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::R:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::S:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::T:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::U:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::V:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::W:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::X:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Y:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Z:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num0:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num1:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num2:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num3:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num4:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num5:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num6:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num7:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num8:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Num9:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::LControl:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::LShift:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::LAlt:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::LSystem:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::RControl:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::RShift:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::RAlt:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::RSystem:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::LBracket:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::RBracket:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Semicolon:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Comma:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Period:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Quote:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Slash:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Backslash:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Tilde:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Equal:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Hyphen:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::PageUp:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::PageDown:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::End:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Home:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Insert:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Delete:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Add:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Subtract:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Multiply:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Divide:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad0:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad1:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad2:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad3:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad4:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad5:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad6:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad7:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad8:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Numpad9:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F1:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F2:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F3:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F4:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F5:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F6:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F7:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F8:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F9:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F10:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F11:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F12:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F13:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F14:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::F15:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::Pause:
            return Arcade::GameEvent::NONE;
        case sf::Keyboard::KeyCount:
            return Arcade::GameEvent::NONE;

        default:
            return Arcade::GameEvent::NONE;
    }
}

Arcade::GameEvent Arcade::Sfml::getEvent()
{
    sf::Event event{};

    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                return keyboardEvent(event);
            case sf::Event::Closed:
                return Arcade::GameEvent::QUIT;
            case sf::Event::MouseButtonPressed:
                return Arcade::GameEvent::NONE;
            case sf::Event::Resized:
                return Arcade::GameEvent::NONE;
            case sf::Event::LostFocus:
                return Arcade::GameEvent::NONE;
            case sf::Event::GainedFocus:
                return Arcade::GameEvent::NONE;
            case sf::Event::TextEntered:
                return Arcade::GameEvent::NONE;
            case sf::Event::KeyReleased:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseWheelMoved:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseWheelScrolled:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseButtonReleased:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseMoved:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseEntered:
                return Arcade::GameEvent::NONE;
            case sf::Event::MouseLeft:
                return Arcade::GameEvent::NONE;
            case sf::Event::JoystickButtonPressed:
                return Arcade::GameEvent::NONE;
            case sf::Event::JoystickButtonReleased:
                return Arcade::GameEvent::NONE;
            case sf::Event::JoystickMoved:
                return Arcade::GameEvent::NONE;
            case sf::Event::JoystickConnected:
                return Arcade::GameEvent::NONE;
            case sf::Event::JoystickDisconnected:
                return Arcade::GameEvent::NONE;
            case sf::Event::TouchBegan:
                return Arcade::GameEvent::NONE;
            case sf::Event::TouchMoved:
                return Arcade::GameEvent::NONE;
            case sf::Event::TouchEnded:
                return Arcade::GameEvent::NONE;
            case sf::Event::SensorChanged:
                return Arcade::GameEvent::NONE;
            case sf::Event::Count:
                return Arcade::GameEvent::NONE;

            default:
                return Arcade::GameEvent::NONE;
        }
    }
    return Arcade::GameEvent::NONE;
}

