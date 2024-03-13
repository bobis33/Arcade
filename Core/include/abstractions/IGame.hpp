/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGame.hpp
*/

#pragma once

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

namespace Arcade {
    class IGame {
    public:
        virtual ~IGame() = default;

        IGame(const IGame &) = delete;
        IGame &operator=(const IGame &) = delete;

    }; // IGame

} // Arcade

#endif // ARCADE_IGAME_HPP
