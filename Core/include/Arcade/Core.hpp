/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

/**
 * @file Core.hpp
 * @brief File declaring Core
 */

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <memory>
#include <vector>

#include "Arcade/Enum.hpp"
#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/abstractions/IWindow.hpp"

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
            /**
            * @brief Core mode
            */
            CoreMode _mode{CoreMode::MENU};

            /**
             * @brief Window renderer
             */
            std::unique_ptr<IRenderer> _renderer{nullptr};

            /**
             * @brief Graphic libraries actives
             */
            std::vector<std::string> _graphicLibraries;

            /**
             * @brief Game libraries actives
             */
            std::vector<std::string> _gameLibraries;

        public:
            Core() = default;
            ~Core() = default;

            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;
            Core(const Core &&) = delete;
            Core &operator=(const Core &&) = delete;

        /**
        * @brief CoreException class
        * @details Exception class for the Core class
        */
        class CoreException : public std::exception
        {
        public:
            explicit CoreException(std::string msg) : _msg{std::move(msg)} {}
            ~CoreException() override = default;

            CoreException(const CoreException &) = delete;
            CoreException &operator=(const CoreException &) = delete;
            CoreException(const CoreException &&) = delete;
            CoreException &operator=(const CoreException &&) = delete;

            [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); };

        private:
            std::string _msg{0};

        }; // Exception

            /**
             * @brief parse arguments
             * @param path
             */
            void parser(const std::string &path);

            /**
             * @brief Run Arcade
             * @param path
             * @return int
             */
            int runArcade(const std::string &path);

            /**
             * @brief Get actives libraries
             */
            void getLibraries();

            /**
             * @brief Game loop
             * @details Main game loop
             */
            void gameLoop();

            /**
             * @brief Handle events
             * @param event
             */
            void handleEvents(const GameEvent &event);

            /**
             * @brief Set the game mode
             * @param gameMode
             */
            void setMode(const CoreMode &gameMode) { _mode = gameMode; };

            /**
             * @brief load graphic
             */
            void loadGraphic();

            /**
             * @brief display menu
             */
            void displayMenu();

            /**
             * @brief Get the renderer
             * @return The renderer
             */
            IRenderer *getRenderer() { return _renderer.get(); };

    }; // Core

} // namespace Arcade

#endif // ARCADE_CORE_HPP
