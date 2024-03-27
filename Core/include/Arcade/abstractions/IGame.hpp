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
        virtual void start() = 0;

        /**
         * @brief stop the game
         */
        virtual void stop() = 0;

    }; // IGame

} // namespace Arcade

#endif // ARCADE_IGAME_HPP
