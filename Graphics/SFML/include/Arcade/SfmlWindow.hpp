/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SfmlWindow.hpp
*/

/**
 * @file SfmlWindow.hpp
 * @brief File declaring SfmlWindow class
 */

#ifndef ARCADE_SFML_WINDOW_HPP
#define ARCADE_SFML_WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/abstractions/IWindow.hpp"

namespace Arcade
{

    /**
    * @brief SfmlWindow class
    * @details SfmlWindow class for the Arcade project
    */
	class SfmlWindow : public IWindow
    {
        public:
            ~SfmlWindow() override = default;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { _window.display(); };
            void clearWindow() override { _window.clear(); };
            void closeWindow() override { _window.close(); };
            void setTitle(const std::string &title) override { _window.setTitle(title); };

            /**
             * @brief Get the current window
             * @return The current window
             */
            sf::RenderWindow *getWindow() { return &_window; };

        private:
            sf::RenderWindow _window;

            unsigned int _width{0};
            unsigned int _height{0};

    }; // SfmlWindow

} // namespace Arcade

#endif // ARCADE_SFML_WINDOW_HPP
