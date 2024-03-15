/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enum.hpp
*/

/**
 * @file Enum.hpp
 *
 * @brief File declaring Enum
 */

#pragma once

#ifndef ARCADE_ENUM_HPP
#define ARCADE_ENUM_HPP

/**
 * @brief Enum for the Arcade project
 * @details Set of enum used in the Arcade project
 */

namespace Arcade {

    enum class CoreMode {
        GAME,
        MENU,
        PAUSE,
        QUIT,
    };

    enum class GameMode {
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
    enum class GameEvent {
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
