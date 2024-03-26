/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IWindow.hpp
*/

/**
 * @file IWindow.hpp
 * @brief File declaring Window Interface
 */

#ifndef ARCADE_IWINDOW_HPP
#define ARCADE_IWINDOW_HPP

#include <iostream>

namespace Arcade {

    /**
     * @brief Window Interface
     * @details Set of method to implement for the business logic of the Arcade project
     */
    class IWindow {
    public:
        virtual ~IWindow() = default;

        /**
         * @brief Create a window with the specified dimensions
         * @param width The width of the window
         * @param height The height of the window
         */
        virtual void openWindow(unsigned int width, unsigned int height) = 0;

        /**
         * @brief Display the current window
         */
        virtual void displayWindow() = 0;

        /**
         * @brief Clear the contents of the current window
         */
        virtual void clearWindow() = 0;

        /**
         * @brief Close the current window
         */
        virtual void closeWindow() = 0;

        /**
         * @brief Set the title of the window
         * @param title The new title of the window
         */
        virtual void setTitle(const std::string &title) = 0;

    }; // IGame

} // namespace Arcade

#endif // ARCADE_IWINDOW_HPP
