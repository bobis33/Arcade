/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/NCursesRenderer.hpp"

Arcade::GameEvent Arcade::NCursesRenderer::getEvent()
{

    switch (getch()) {
        case KEY_UP:
            return GameEvent::UP;
        case KEY_DOWN:
            return GameEvent::DOWN;
        case KEY_LEFT:
            return GameEvent::LEFT;
        case KEY_RIGHT:
            return GameEvent::RIGHT;
        case 'q':
            return GameEvent::QUIT;

        default:
            return GameEvent::NONE;
    }
}
