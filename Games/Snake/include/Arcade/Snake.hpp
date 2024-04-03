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

#include "Arcade/abstractions/AGame.hpp"

namespace Arcade {
    class Snake : public AGame {
        public:
            void loadGame() override;
            void displayGame() override;
            void stop() override {};
            void handleEvents(const KeyboardEvents &event) override;

            void moveSnake(const std::string &snakePart);
            void moveBody();
            void createMap();
            void replaceFood();
            std::pair<int, int> getBodyPosition();
            void checkLose();
        private:
            std::pair<float, float> **_map;
            int _snakeSize{1};
            std::vector<std::pair<int, int>> _snake;
            std::pair<int, int> _mapPosition{0, 0};
            std::pair<int, int> *_mapPositionBody{nullptr};
            std::pair<int, int> _mapPositionFood{2, 2};

    }; // Snake

} // namespace Arcade

#endif // ARCADE_SNAKE_HPP
