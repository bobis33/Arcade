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
            void displayWindow() override { box(_window, 0, 0); mvprintw(0, _titlePos, "%s", _title.data()); };
            void clearWindow() override { wrefresh(_window); wclear(_window); };
            void closeWindow() override { curs_set(1); reset_shell_mode(); endwin(); delwin(_window); };
            void setTitle(const std::string &title) override { _title = title; };

            /**
             * @brief Get the current window
             * @return The current window
             */
            WINDOW *getWindow() { return _window; };

        private:
            WINDOW *_window;
            std::string _title{" Arcade - NCurses "};
            int _titlePos{0};

	}; // NCursesWindow

} // namespace Arcade

#endif // ARCADE_NCURSES_WINDOW_HPP
