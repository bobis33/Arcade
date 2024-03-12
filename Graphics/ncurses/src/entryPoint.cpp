/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** entryPoint.cpp
*/

#include "Ncurses.hpp"

extern "C" {
    std::unique_ptr<Arcade::AGraphic> entryPoint() {
        std::unique_ptr<Arcade::Ncurses> ncurses = std::make_unique<Arcade::Ncurses>();
        return ncurses->openWindow();
    }
}