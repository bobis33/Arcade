/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

/**
 * @file Ncurses.hpp
 * @brief File declaring Ncurses
 */

#pragma once

#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include <ncurses.h>
#include <string_view>
#include "Arcade/abstractions/IRenderer.hpp"

namespace Arcade
{

    /**
    * @brief Ncurses class
    * @details Ncurses class for the Arcade project
    */
	class Ncurses : public IRenderer
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
            void setTitle(const std::string &title) override { _title = title; };
            void displayMenu() override{};

        private:
            WINDOW *_window{nullptr};
            std::string_view _title{"Arcade - NCurses\n"};

	}; // NCurses
} // Arcade

#endif // ARCADE_NCURSES_HPP
