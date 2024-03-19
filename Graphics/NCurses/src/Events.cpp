/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Events.cpp
*/

#include "Arcade/Ncurses.hpp"

Arcade::GameEvent Arcade::Ncurses::getEvent()
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
