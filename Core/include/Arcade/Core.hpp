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

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/abstractions/IWindow.hpp"
#include "Arcade/abstractions/IGame.hpp"

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
            CoreMode _mode{CoreMode::LOGIN};

            /**
             * @brief Window renderer
             */
            std::unique_ptr<IRenderer> _renderer{nullptr};

            /**
             * @brief Game instance
             */
            std::unique_ptr<IGame> _game{nullptr};

            /**
             * @brief Graphic libraries actives
             */
            std::vector<std::string> _graphicLibs;

            /**
             * @brief Game libraries actives
             */
            std::vector<std::string> _gameLibs;

            /**
             * @brief Current graphic index
             */
            size_t _currentGraphicIndex{0};

            /**
             * @brief Current game index
             */
            size_t _currentGameIndex{0};

            /**
             * @brief Handle graphic
             * @details void *, store for dlclose
             */
            void *_handleGraphic{nullptr};

            /**
             * @brief Handle game
             * @details void *, store for dlclose
             */
            void *_handleGame{nullptr};

            std::string _userName;

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

        }; // CoreException

            /**
             * @brief Run Arcade
             * @param path
             * @return int
             */
            int runArcade(const std::string &path);

            /**
             * @brief Get actives libraries
             */
            void getLibraries(const std::string &libPath);

            /**
             * @brief Get next library index
             * @param libs
             * @param currentIndex
             * @return size_t
             */
            static size_t getNextLibIndex(std::vector<std::string> &libs, size_t currentIndex);

            /**
             * @brief Get previous library index
             * @param libs
             * @param currentIndex
             * @return size_t
             */
             static size_t getPreviousLibIndex(std::vector<std::string> &libs, size_t currentIndex);

            /**
             * @brief Switch Graphic library
             */
            void switchGraphicLibrary();

            /**
             * @brief Switch library
             * @tparam T
             * @param libPath
             */
            template<typename T>
            void switchLib(const std::string &libPath);

            /**
             * @brief Game loop
             * @details Main game loop
             */
            void mainLoop();

            /**
             * @brief Set the game mode
             * @param gameMode
             */
            void setMode(const CoreMode &gameMode) { _mode = gameMode; };

            /**
             * @brief Load renderer
             * @param path
             */
            void loadRenderer(const std::string &path);

            /**
             * @brief load Menu
             */
            void loadMenu();

            /**
             * @brief display menu
             */
            void displayMenu();

            /**
             * @brief Get the renderer
             * @return The renderer
             */
            IRenderer *getRenderer() { return _renderer.get(); };

            void moveCursorDown();

            void moveCursorUp();

            void launchGame();

            void setGameIndex(size_t index) { _currentGameIndex = index; };

            CoreMode getMode() { return _mode; };

            void setUserName(const std::string &userName) { _userName = userName; };

            void loadLogin();

            void displayLoginScreen();

    }; // Core

} // namespace Arcade

#endif // ARCADE_CORE_HPP
