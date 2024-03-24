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

#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include <ncurses.h>

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
            ~Ncurses() override = default;

            GameEvent getEvent() override;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { refresh(); mvprintw(0, _titlePos, "%s", _title.data()); };
            void clearWindow() override { clear(); };
            void closeWindow() override { curs_set(1); delwin(_window); endwin(); };
            void setTitle(const std::string &title) override { _title = title; };

            bool loadTexture(const std::string &texture, const std::string &name) override { (void)texture; (void)name; return true;};
            bool loadFont(const std::string &filepath, const std::string &name) override {(void) filepath; (void) name; return true;};
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override {(void)textureName; (void)pos_x; (void)pos_y; (void)scale_x; (void)scale_y;};
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override {(void)text; (void)fontName; (void)size; (void)pos_x; (void)pos_y;};
            void displaySprite(const std::string &spriteName) override {(void)spriteName;};
            void displayText(const std::string &textName) override {(void)textName;};

            bool isASCII() override { return true; };
        private:
            WINDOW *_window{nullptr};
            std::string _title{"Arcade - NCurses\n"};
            int _titlePos{0};

	}; // NCurses

} // namespace Arcade

#endif // ARCADE_NCURSES_HPP
