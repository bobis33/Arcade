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

#include <vector>
#include <memory>

#include "Arcade/abstractions/IGame.hpp"
#include "Arcade/abstractions/IRenderer.hpp"

namespace Arcade {
    class Nibbler : public AGame {
        public:
            ~Nibbler() override = default;

            void start(std::reference_wrapper<IRenderer> renderer) override {(void)renderer;};
            void displayGame() override {};
            void stop() override {};
            void handleEvents(KeyboardEvents event) override;

    }; // Nibbler

} // namespace Arcade

#endif // ARCADE_NIBBLER_HPP
