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
#include "Arcade/Enum.hpp"
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
            */
            virtual void start(std::reference_wrapper<IRenderer> renderer, Clock &clock) = 0;

            /**
            * @brief load the game
            */
            virtual void loadGame() = 0;

            /**
            * @brief display the game
            */
            virtual void displayGame() = 0;

            /**
            * @brief stop the game
            */
            virtual void stop() = 0;

            /**
            * @brief handle the game event
            */
            virtual void handleEvents(KeyboardEvents event) = 0;

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

    }; // IGame

} // namespace Arcade

#endif // ARCADE_IGAME_HPP
