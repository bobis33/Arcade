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

#include <vector>
#include <memory>

#include "Arcade/abstractions/AGame.hpp"

namespace Arcade {
    class Nibbler : public AGame {
        public:
            void loadGame() override {};
            void displayGame() override {};
            void stop() override {};
            void handleEvents(KeyboardEvents key) override {(void)key;};

    }; // Nibbler

} // namespace Arcade

#endif // ARCADE_NIBBLER_GAME_HPP
