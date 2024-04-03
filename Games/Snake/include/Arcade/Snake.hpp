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

            void moveSnake(std::string snakePart);
            void moveBody();
            int getSnakeSize() const { return _snakeSize; };
            [[nodiscard]] std::vector<std::pair<int, int>> getSnake() const { return _snake; };
            void createMap();
            void replace_apple();
            std::pair<int, int> findWherePlaceBody();
            int checkIfCorner(Direction direction, Direction lastDirection);

        private:
            std::pair<float, float> **_map;
            int _snakeSize{1};
            std::vector<std::pair<int, int>> _snake;
            std::pair<int, int> _lastDirection{1, 0};
            std::pair<int, int> _mapPosition{0, 0};
            std::pair<int, int> *_mapPositionBody{nullptr};
            std::pair<int, int> _mapPositionApple{2, 2};
    };
}

#endif // ARCADE_SNAKE_GAME_HPP
