/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enum.hpp
*/

/**
 * @file Enum.hpp
 * @brief File declaring Enum
 * @details Set of enum used in the Arcade project
 */

#ifndef ARCADE_ENUM_HPP
#define ARCADE_ENUM_HPP

namespace Arcade {

    enum class CoreMode : std::uint8_t {
        GAME,
        MENU,
        PAUSE,
        QUIT,
    };

    enum class GameMode : std::uint8_t {
        GAME,
        GAME_OVER,
        MENU,
        PAUSE,
        QUIT,
    };

    /**
     * @brief Enum for the GameEvent
     * @details Set of enum used for the game event
     */
    enum class GameEvent : std::uint8_t {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SHOOT,
        PAUSE,
        QUIT,
        NONE,
    };

} // Arcade

#endif // ARCADE_ENUM_HPP
