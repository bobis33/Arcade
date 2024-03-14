/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Enum.hpp
*/

#pragma once

#ifndef ARCADE_ENUM_HPP
#define ARCADE_ENUM_HPP

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
