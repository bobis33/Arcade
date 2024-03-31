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

    enum class CoreMode {
        GAME,
        MENU,
        QUIT,
    };

    enum class GameMode {
        GAME,
        GAME_OVER,
        PAUSE,
    };

    /**
     * @brief Enum for the KeyboardEvents
     * @details Set of enum used for the game event
     */
    enum class KeyboardEvents {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        CLICK,
        ESC,
        F1,
        ENTER,
        NONE,
    };

} // Arcade

#endif // ARCADE_ENUM_HPP
