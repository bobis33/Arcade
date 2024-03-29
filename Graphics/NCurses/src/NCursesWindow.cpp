/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCursesRenderer.cpp
*/

#include <signal.h>

#include "Arcade/NCursesWindow.hpp"

void Arcade::NCursesWindow::openWindow(const unsigned int width, const unsigned int height)
{
    (void)width; (void)height;
    int size_title = 0;
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    _window = newwin(0, 0, 0, 0);
    for (; _title.data()[size_title] != 0; size_title++);
    _titlePos = (COLS - size_title) / 2;
    signal(SIGWINCH, [](int sig) {
        if (sig == SIGWINCH) {
            resize_term(0, 0);
        }
    });
    wrefresh(_window);
}
