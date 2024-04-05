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

    static constexpr int MAP_WIDTH = 12;
    static constexpr int MAP_HEIGHT = 10;

    static constexpr int SIZE_BOX = 90;
    static constexpr int NB_MOVES = 120;

    static constexpr int BILLBOARD_POSITION = 1350;
    static constexpr int SIZE_TITLE = 40;
    static constexpr int SIZE_TEXT = 30;
    static constexpr int MOVE_SPEED = 600;

    class Snake : public AGame {
        public:
            void loadGame() override;
            void gameLoop() override;
            void handleEvents(const KeyboardEvents &event) override;

            void moveSnake();
            void moveBody();
            void createMap();
            void replaceFood();
            void checkLose();
            void displaySnake();
            void isEating();
            std::pair<size_t, size_t> getBodyPosition();

        private:
            size_t _snakeSize{1};
            std::pair<size_t, size_t> _mapPosition{5, 5};
            std::vector<std::pair<size_t, size_t>> _mapPositionBody;
            std::pair<size_t, size_t> _mapPositionFood{2, 2};
            int _moveSpeed{MOVE_SPEED};
            int _increaseSpeed{0};
            std::pair<size_t, size_t> _bodyPosition;

    }; // Snake

} // namespace Arcade

#endif // ARCADE_SNAKE_HPP
