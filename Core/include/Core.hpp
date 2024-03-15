/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

/**
 * @file Core.hpp
 *
 * @brief File declaring Core
 */

#pragma once

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <iostream>
#include <exception>
#include <memory>
#include "Enum.hpp"
#include "abstractions/AGraphic.hpp"

/**
 * @namespace Arcade
 * @brief Main namespace for the Arcade project
 */

namespace Arcade
{
    /**
     * @brief Core class
     * @details Core class for the Arcade project
     */

    class Core
    {
        private:
            CoreMode _mode{CoreMode::MENU};
            std::unique_ptr<AGraphic> _window{nullptr};

        public:
            Core() = default;
            ~Core() = default;

            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;

            void parser(const std::string &path);
            int runArcade(const std::string &path);

            /**
             * @brief Game loop
             * @details Main game loop
             */
            void gameLoop();
            void handleEvents(const GameEvent &event);
            /**
             * @brief Set the mode object
             * @param gameMode
             */
            void setMode(const CoreMode &gameMode) { _mode = gameMode; };
            void closeWindow() { _window->closeWindow(); };

         /**
          * @brief CoreException class
          * @details Exception class for the Core class
          */
        class CoreException : public std::exception
        {
            public:
                explicit CoreException(std::string msg) : _msg{std::move(msg)} {}
                ~CoreException() override = default;

                CoreException(CoreException const &) = delete;

            [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); };

            private:
                std::string _msg;

        }; // Exception

    }; // Core

} // Arcade

#endif // ARCADE_CORE_HPP
