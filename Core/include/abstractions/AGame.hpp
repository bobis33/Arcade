/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame.hpp
*/

#pragma once

#ifndef ARCADE_AGAME_HPP
#define ARCADE_AGAME_HPP

#include "IGame.hpp"

namespace Arcade {
    class AGame : public IGame {
    public:
        ~AGame() override = default;
    }; // AGame
} // Arcade

#endif // ARCADE_AGAME_HPP
