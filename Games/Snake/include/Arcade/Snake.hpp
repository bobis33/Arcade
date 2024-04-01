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

#ifndef ARCADE_SNAKE_GAME_HPP
#define ARCADE_SNAKE_GAME_HPP

#include "Arcade/abstractions/AGame.hpp"

namespace Arcade {
    class Snake : public AGame {
        public:
            void loadGame() override;
            void displayGame() override;
            void stop() override {};
            void handleEvents(KeyboardEvents event) override;

            void moveSnake();
            int getSnakeSize() const { return _snakeSize; };
            [[nodiscard]] std::vector<std::pair<int, int>> getSnake() const { return _snake; };
            void createMap();
            void replace_apple();

        private:
            std::pair<float, float> **_map;
            int _snakeSize{1};
            std::vector<std::pair<int, int>> _snake;
            std::pair<int, int> _food;
            std::pair<int, int> _lastDirection{1, 0};
            std::pair<int, int> _mapPosition{0, 0};
            std::pair<int, int> _mapPositionApple{4, 4};
    };
}

#endif // ARCADE_SNAKE_GAME_HPP
