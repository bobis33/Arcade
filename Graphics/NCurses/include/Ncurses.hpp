/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include <ncurses.h>
#include <string_view>
#include "abstractions/AGraphic.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - NCurses\n";

namespace Arcade
{
	class Ncurses : public AGraphic
    {
        public:
            Ncurses();
            ~Ncurses() override = default;

            Ncurses(const Ncurses &) = delete;
            Ncurses &operator=(const Ncurses &) = delete;

            GameEvent getEvent() override;

            void displayWindow() override { refresh(); };
            void clearWindow() override { clear(); };
            void closeWindow() override { curs_set(1); delwin(_window); endwin(); };

        private:
            WINDOW *_window = nullptr;

	}; // NCurses
} // Arcade

#endif // ARCADE_NCURSES_HPP
