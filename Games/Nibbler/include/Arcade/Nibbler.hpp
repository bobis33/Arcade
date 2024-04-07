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
             * @brief Create the wall in std::vector<std::vector<char>>
            */
            void createWall();

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
             * @brief Check if the snake can move
             * @param pos The position of the snake
             * @param direction The direction of the snake
            */
            void checkIfCanMove(std::pair<size_t, size_t> pos, const Direction &direction);

            /**
             * @brief Get the position of the body
             * @return The position of the body
            */
            std::pair<size_t, size_t> getBodyPosition();

            /**
             * @brief Find the direction of the snake
             * @param direction The direction of the snake
             * @return True if the direction is found, false otherwise
            */
            bool findDirection(const Direction &direction);

            /**
             * @brief Create the food
            */
            void createFood();

            /**
             * @brief Display the food
            */
            void displayFood();

            /**
             * @brief Turn the last body of the snake
             * @param bodystring The body of the snake
            */
            void turnLastBody(std::string bodystring);

            /**
             * @brief Check if the snake is winning
            */
            void checkWin();

            /**
             * @brief Reset the game
            */
            void resetGame();

            /**
             * @brief Load the nibbler
            */
            void loadNibbler();
            
            /**
             * @brief Load the ascii nibbler
            */
            void loadASCIINibbler();

            /**
             * @brief Create the snake
            */
            void createSnake();

        private:

            /**
             * @brief The size of the snake
            */
            size_t _snakeSize{1};
            
            /**
             * @brief The position of the snake
            */
            std::pair<size_t, size_t> _mapPosition{16, 9};
            
            /**
             * @brief The position of the body
            */
            std::vector<std::pair<size_t, size_t>> _mapPositionBody;
            
            /**
             * @brief The position of the food
            */
            std::vector<std::pair<std::pair<size_t, size_t>, bool>> _mapPositionFood{{std::make_pair(0, 0), false}};
            
            /**
             * @brief The speed of the snake
            */
            int _moveSpeed{MOVE_SPEED};
            
            /**
             * @brief The delay between each increase of speed
            */
            int _increaseSpeed{0};

            /**
             * @brief The position of the body
            */
            std::pair<size_t, size_t> _bodyPosition;
            
            /**
             * @brief If the snake can move
            */
            bool _canMove{true};

            /**
             * @brief The wall of the map
            */
            std::vector<std::vector<char>> _mapPositionWall;

            /**
             * @brief The number of food
            */
            size_t _nbFood{0};

            /**
             * @brief If the game is in ascii mode
            */
            bool _isAscii{false};

            /**
             * @brief The number of food left
            */
            int _foodLeft{0};

            /**
             * @brief The level of the game
            */
            int _lvl{1};

    }; // Nibbler

} // namespace Arcade

#endif // ARCADE_NIBBLER_HPP
