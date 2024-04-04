/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCursesRenderer.cpp
*/

#include "Arcade/NCursesWindow.hpp"

void Arcade::NCursesWindow::openWindow(const unsigned int width, const unsigned int height)
{
    int size_title = 0;
    _size = std::make_pair(static_cast<int>(width), static_cast<int>(height));
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);
    _window = newwin(_size.second, _size.first, 0, 0);
    refresh();
    for (; _title.data()[size_title] != 0; size_title++);
    _titlePos = (_size.first - size_title) / 2;
}
