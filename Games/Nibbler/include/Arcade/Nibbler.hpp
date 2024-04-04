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

#ifndef ARCADE_NIBBLER_HPP
#define ARCADE_NIBBLER_HPP

#include "Arcade/abstractions/AGame.hpp"

namespace Arcade {
    class Nibbler : public AGame {
        public:
            void loadGame() override;
            void displayGame() override {};
            void stop() override {};
            void handleEvents(const KeyboardEvents &event) override;

    }; // Nibbler

} // namespace Arcade

#endif // ARCADE_NIBBLER_HPP
