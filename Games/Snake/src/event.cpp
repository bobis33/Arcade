/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** event
*/

#include "Arcade/Snake.hpp"
#include "Arcade/EventsManager.hpp"

static constexpr float MOVE_SPEED = 10;

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Snake &)>> MAP_GAME_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(-MOVE_SPEED, 0);
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(MOVE_SPEED, 0);
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(0, -MOVE_SPEED);
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(0, MOVE_SPEED);
                }},
};

void Arcade::Snake::handleEvents(KeyboardEvents event)
{
    EventManager::handleEvent(MAP_GAME_EVENT, *this, event);
}