/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/NCursesRenderer.hpp"

Arcade::KeyboardEvents Arcade::NCursesRenderer::getEvent()
{
    int ch = getch();

    switch (ch) {
        case KEY_UP:
            return KeyboardEvents::UP;
        case KEY_DOWN:
            return KeyboardEvents::DOWN;
        case KEY_LEFT:
            return KeyboardEvents::LEFT;
        case KEY_RIGHT:
            return KeyboardEvents::RIGHT;
        case KEY_F(1):
            return KeyboardEvents::F1;
        case KEY_F(2):
            return KeyboardEvents::F2;
        case 27:
            return KeyboardEvents::ESC;
        case ERR:
            return KeyboardEvents::NONE;
        case 10:
            _isLogged = true;
            return KeyboardEvents::ENTER;

        default:
            if(_isLogged)
                return KeyboardEvents::NONE;
            if(ch >= 32 && ch <= 126) {
                _userName += static_cast<char>(ch);
                return KeyboardEvents::TEXTENTERED;
            } else if(ch == 263) {
                if (_userName.size() > 0)
                    _userName.pop_back();
                return KeyboardEvents::TEXTENTERED;
            } else {
                return KeyboardEvents::NONE;
            }
    }
    return KeyboardEvents::NONE;
}
