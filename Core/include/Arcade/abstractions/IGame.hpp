/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGame.hpp
*/

/**
 * @file IGame.hpp
 * @brief File declaring Game Interface
 */

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

#include <functional>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Constants.hpp"
#include "Arcade/Clock/Clock.hpp"

namespace Arcade {

    /**
    * @brief Game Interface
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class IGame {
        public:
            virtual ~IGame() = default;

            /**
            * @brief start the game
            * @param renderer The renderer
            * @param clock The clock
            */
            virtual void start(std::reference_wrapper<IRenderer> renderer, const Clock &clock) = 0;

            /**
            * @brief load the game
            */
            virtual void loadGame() = 0;

            /**
            * @brief display the game
            */
            virtual void gameLoop() = 0;

            /**
            * @brief stop the game
            */
            virtual void stop() = 0;

            /**
            * @brief handle the game event
            * @param event The event
            */
            virtual void handleEvents(const KeyboardEvents &event) = 0;

            /**
             * @brief Get the score
             * @return The score
             */
            virtual int getScore() const = 0;

            /**
             * @brief Get the game mode
             * @return The game mode
             */
            virtual GameMode getGameMode() const = 0;

            /**
             * @brief Get the direction
             * @return The direction
             */
            virtual Direction getDirection() const = 0;

            /**
             * @brief Set the direction
             * @param direction The direction
             */
            virtual void setDirection(const Direction &direction) = 0;

            /**
             * @brief Randomize a number
             * @param min The minimum value
             * @param max The maximum value
             * @return The random number
             */
            virtual int randomize(int min, int max) = 0;

            /**
             * @brief Get the user name
             * @param name The user name
             */
            virtual void getUserName(const std::string &name) = 0;

    }; // IGame

} // namespace Arcade

#endif // ARCADE_IGAME_HPP
