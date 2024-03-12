/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include "abstractions/AGraphic.hpp"

namespace Arcade
{
	class Ncurses : public AGraphic
    {
        public:
            Ncurses() = default;
            ~Ncurses() override = default;

            Ncurses(const Ncurses &) = delete;
            Ncurses &operator=(const Ncurses &) = delete;

            void openWindow() override final;
            void closeWindow() override final;
            void clearWindow() override final;
            void displayWindow() override final;

        private:
            WINDOW *_window = nullptr;

	}; // ncurses
}

#endif // ARCADE_NCURSES_HPP
