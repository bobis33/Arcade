/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Nibbler.hpp
*/

/**
 * @file Nibbler.hpp
 * @brief Defines the Nibbler class.
*/

#ifndef ARCADE_NIBBLER_GAME_HPP
#define ARCADE_NIBBLER_GAME_HPP

#include "Arcade/abstractions/IGame.hpp"

namespace Arcade {
    class Nibbler : public IGame {
        public:
            ~Nibbler() override = default;

            void start() override {};
            void stop() override {};
    }; 
}

#endif // ARCADE_NIBBLER_GAME_HPP
