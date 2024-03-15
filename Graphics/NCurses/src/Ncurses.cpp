/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include <cstring>
#include "Ncurses.hpp"

constexpr char const *TITLE = "Arcade - Ncurses";

Arcade::Ncurses::Ncurses()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    _window = newwin(20, 80, 0, 0);
    curs_set(0);
    box(_window, 0, 0);
    mvprintw(0, (COLS - static_cast<int>(strlen(TITLE))) / 2, TITLE);
    wrefresh(_window);
}
