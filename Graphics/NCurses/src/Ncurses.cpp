/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "Ncurses.hpp"

#define WINDOW_TITLE_POSITION ((COLS - 17) / 2)

Arcade::Ncurses::Ncurses()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    _window = newwin(20, 80, 0, 0);
    mvprintw(0, WINDOW_TITLE_POSITION, WINDOW_TITLE.data());
    wrefresh(_window);
}
