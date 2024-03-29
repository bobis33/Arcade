/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/NCursesRenderer.hpp"

Arcade::KeyboardEvents Arcade::NCursesRenderer::getEvent()
{

    switch (getch()) {
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
        case 27:
            return KeyboardEvents::ESC;
        default:
            return KeyboardEvents::NONE;
    }
}