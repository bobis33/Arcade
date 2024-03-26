/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCursesWindow.hpp
*/

/**
 * @file NCursesWindow.hpp
 * @brief File declaring NCursesWindow
 */

#ifndef ARCADE_NCURSES_WINDOW_HPP
#define ARCADE_NCURSES_WINDOW_HPP

#include <ncurses.h>

#include "Arcade/abstractions/IWindow.hpp"

namespace Arcade
{

    /**
    * @brief NCursesWindow class
    * @details NCursesWindow class for the Arcade project
    */
    class NCursesWindow : public IWindow
    {
        public:
            ~NCursesWindow() override = default;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { refresh(); mvprintw(0, _titlePos, "%s", _title.data()); };
            void clearWindow() override { clear(); };
            void closeWindow() override { curs_set(1); delwin(_window); endwin(); };
            void setTitle(const std::string &title) override { _title = title; };

            /**
             * @brief Get the current window
             * @return The current window
             */
            WINDOW *getWindow() { return _window; };

        private:
            WINDOW *_window{nullptr};
            std::string _title{"Arcade - NCurses\n"};
            int _titlePos{0};

	}; // NCursesWindow

} // namespace Arcade

#endif // ARCADE_NCURSES_WINDOW_HPP
