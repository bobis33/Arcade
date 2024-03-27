/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

/**
 * @file Snake.hpp
 * @brief Defines the Snake class.
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Arcade/abstractions/IGame.hpp"
#include <vector>

namespace Arcade {
    class Snake : public IGame {
        public:
            ~Snake() override = default;

            void start() override {};
            void stop() override {};

            int getScore() const { return _score; };
            int getSnakeSize() const { return _snakeSize; };
            std::vector<std::pair<int, int>> getSnake() const { return _snake; };


        private:
            int _score{0};
            int _snakeSize{1};
            std::vector<std::pair<int, int>> _snake;
            std::pair<int, int> _food;
            std::pair<int, int> _direction{1, 0};
            std::pair<int, int> _lastDirection{1, 0};
            bool _gameOver{false};
    }; 
}

#endif /* !SNAKE_HPP_ */
