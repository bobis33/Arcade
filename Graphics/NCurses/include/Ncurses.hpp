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
#include "abstractions/AGraphic.hpp"

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

            void openWindow();
            void closeWindow();

        private:
            WINDOW *_window = nullptr;

	}; // NCurses
}

#endif // ARCADE_NCURSES_HPP
