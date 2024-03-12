/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include <ncurses.h>
#include "Ncurses.hpp"

void Arcade::Ncurses::openWindow()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    _window = newwin(20, 80, 0, 0);
    box(_window, 0, 0);
    wrefresh(_window);
}

void Arcade::Ncurses::closeWindow()
{
    delwin(_window);
    endwin();
}

void Arcade::Ncurses::clearWindow()
{
    werase(_window);
    wrefresh(_window);
}

void Arcade::Ncurses::displayWindow()
{
    wrefresh(_window);
}