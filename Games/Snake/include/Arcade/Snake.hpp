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

            /**
             * @brief Move the head of the snake
             */
            void moveSnake();
            
            /**
             * @brief Move the body of the snake
             */
            void moveBody();
            
            /**
             * @brief Create the map in std::vector<size_t, size_t>
             */
            void createMap();
            
            /**
             * @brief Replace food after eating
             */
            void replaceFood();

            /**
             * @brief Check if the head of the snake is touching his body
             */
            void checkLose();

            /**
             * @brief Display the snake
             */
            void displaySnake();

            /**
             * @brief Check if the snake is eating
             */
            void isEating();

            /**
             * @brief Get the position of the body
             * @return position of the body
             */
            std::pair<size_t, size_t> getBodyPosition();

            /**
             * @brief Turn the last body of the snake
             * @param The string of the body
             */
            void turnLastBody(std::string bodystring);

            /**
             * @brief Load the snake
             */
            void loadSnake();

            /**
             * @brief Load the ascii snake
             */
            void loadAsciiSnake();


        private:

            /**
             * @brief The size of the snake
             */
            size_t _snakeSize{1};

            /**
             * @brief The position of the snake
             */
            std::pair<size_t, size_t> _mapPosition{5, 5};

            /**
             * @brief The position of the body
             */
            std::vector<std::pair<size_t, size_t>> _mapPositionBody;

            /**
             * @brief The position of the food
             */
            std::pair<size_t, size_t> _mapPositionFood{2, 2};

            /**
             * @brief The speed of the snake
             */
            int _moveSpeed{MOVE_SPEED};

            /**
             * @brief The delay of the snake
             */
            int _increaseSpeed{0};

            /**
             * @brief The position of the body
             */
            std::pair<size_t, size_t> _bodyPosition;

            /**
             * @brief If is ascii
             */
            bool _isAscii{false};

    }; // Snake

} // namespace Arcade

#endif // ARCADE_SNAKE_HPP
