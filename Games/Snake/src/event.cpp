/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** event
*/

#include <map>
#include <functional>

#include "Arcade/Snake.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Snake &)>> MAP_GAME_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(-10, 0);
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(10, 0);
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(0, -10);
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Snake &snake) -> void {
                    snake.moveSnake(0, 10);
                }},
};

void Arcade::Snake::handleEvents(KeyboardEvents key)
{
    auto map_event = MAP_GAME_EVENT.find(key);
        if (map_event != MAP_GAME_EVENT.end()) {
            map_event->second(*this);
        }
}