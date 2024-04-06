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

    static constexpr int MAP_WIDTH = 17;
    static constexpr int MAP_HEIGHT = 17;

    static constexpr int SIZE_BOX = 57;
    static constexpr int NB_MOVES = 289;

    static constexpr int BILLBOARD_POSITION = 1180;
    static constexpr int SIZE_TITLE = 40;
    static constexpr int SIZE_TEXT = 30;
    static constexpr int MOVE_SPEED = 600;

    class Nibbler : public AGame {
        public:
            void loadGame() override;
            void gameLoop() override;
            void handleEvents(const KeyboardEvents &event) override;
            void setDirection(const Direction &direction) override;

            void moveSnake();
            void moveBody();
            void createMap();
            void createWall();
            void checkLose();
            void displaySnake();
            void isEating();
            void checkIfCanMove(std::pair<size_t, size_t> pos, const Direction &direction);
            std::pair<size_t, size_t> getBodyPosition();
            bool findDirection(const Direction &direction);
            void createFood();
            void displayFood();

            void loadNibbler();
            void loadASCIINibbler();
            void createSnake();

        private:
            size_t _snakeSize{1};
            std::pair<size_t, size_t> _mapPosition{16, 9};
            std::vector<std::pair<size_t, size_t>> _mapPositionBody;
            std::vector<std::pair<std::pair<size_t, size_t>, bool>> _mapPositionFood{{std::make_pair(0, 0), false}};
            int _moveSpeed{MOVE_SPEED};
            int _increaseSpeed{0};
            std::pair<size_t, size_t> _bodyPosition;
            bool _canMove{true};
            std::vector<std::vector<char>> _mapPositionWall;
            size_t _nbFood{0};
            bool _isAscii{false};

    }; // Nibbler

} // namespace Arcade

#endif // ARCADE_NIBBLER_HPP
