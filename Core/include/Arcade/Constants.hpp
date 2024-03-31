/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** constants.hpp
*/

/**
 * @file Constants.hpp
 * @brief File containing constant values used in the Arcade project
 * @details This file provides a set of constant values that are used throughout the Arcade project.
 */

#ifndef ARCADE_CONSTANTS_HPP
#define ARCADE_CONSTANTS_HPP

/**
 * @brief Exit code for Epitech errors
 */
constexpr int EPITECH_ERROR = 84;

/**
 * @brief Exit code indicating that the program has executed successfully
 */
constexpr int SUCCESS = 0;

/**
 * @brief Exit code indicating that an error has occurred
 */
constexpr int ERROR = -1;

/**
 * @brief Width of the window
 */
constexpr int WIDTH = 1920;

/**
 * @brief Height of the window
 */
constexpr int HEIGHT = 1080;

constexpr char const *LIB_PATH = "./lib/";

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
}

#endif // ARCADE_CONSTANTS_HPP
