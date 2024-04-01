/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** event
*/

#include <map>

#include "Arcade/Snake.hpp"
#include "Arcade/EventsManager.hpp"


static constexpr float MOVE_SPEED = 10;

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Snake &)>> MAP_GAME_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Snake &snake) -> void {
                    snake.setDirection(Arcade::Direction::LEFT);
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Snake &snake) -> void {
                    snake.setDirection(Arcade::Direction::RIGHT);
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Snake &snake) -> void {
                    snake.setDirection(Arcade::Direction::UP);
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Snake &snake) -> void {
                    snake.setDirection(Arcade::Direction::DOWN);
                }},
};

void Arcade::Snake::handleEvents(KeyboardEvents event)
{
    EventManager::handleEvent(MAP_GAME_EVENT, *this, event);
}