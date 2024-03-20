/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "Arcade/Ncurses.hpp"

Arcade::Ncurses::Ncurses()
{
    int size_title = 0;
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    _window = newwin(0, 0, 0, 0);
    for (; _title.data()[size_title]; size_title++);
    const int title_position = (COLS - size_title) / 2;
    mvprintw(0, title_position, "%s", _title.data());
    wrefresh(_window);
}
