/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "Arcade/Ncurses.hpp"

void Arcade::Ncurses::openWindow(const unsigned int width, const unsigned int height)
{
    (void)width; (void)height;
    int size_title = 0;
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    _window = newwin(0, 0, 0, 0);
    for (; _title.data()[size_title]; size_title++);
    _titlePos = (COLS - size_title) / 2;
    wrefresh(_window);
}
