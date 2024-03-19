/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include <cstring>
#include "Arcade/Ncurses.hpp"


Arcade::Ncurses::Ncurses()
{
    int index = 0;
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    _window = newwin(20, 80, 0, 0);
    for (; _title.data()[index]; index++);
    const int window_position = (COLS - index) / 2;
    mvprintw(0, window_position, "%s", _title.data());
    wrefresh(_window);
}
