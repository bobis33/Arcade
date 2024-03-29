/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake.hpp
*/

/**
 * @file Snake.hpp
 * @brief Defines the Snake class.
*/

#ifndef ARCADE_SNAKE_HPP
#define ARCADE_SNAKE_HPP

#include <vector>
#include <memory>

#include "Arcade/abstractions/IGame.hpp"
#include "Arcade/abstractions/IRenderer.hpp"

namespace Arcade {
    class Snake : public AGame {
        public:
            ~Snake() override = default;

            void start(std::reference_wrapper<IRenderer> renderer) override;
            void displayGame() override;
            void stop() override {};
            void handleEvents(KeyboardEvents event) override;

        private:
            int _snakeSize{1};
            std::vector<std::pair<int, int>> _snake;
            std::pair<int, int> _food;
            std::pair<int, int> _direction{1, 0};
            std::pair<int, int> _lastDirection{1, 0};

    }; // Snake

} // namespace Arcade

#endif // ARCADE_SNAKE_HPP
