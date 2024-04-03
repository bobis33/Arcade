/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** event
*/

#include "Arcade/Snake.hpp"
#include "Arcade/EventsManager.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Snake &)>> MAP_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Snake &snake) -> void {
                    if (snake.getDirection() != Arcade::Direction::RIGHT) 
                        snake.setDirection(Arcade::Direction::LEFT);
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Snake &snake) -> void {
                    if (snake.getDirection() != Arcade::Direction::LEFT)
                        snake.setDirection(Arcade::Direction::RIGHT);
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Snake &snake) -> void {
                    if (snake.getDirection() != Arcade::Direction::DOWN)
                        snake.setDirection(Arcade::Direction::UP);
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Snake &snake) -> void {
                    if (snake.getDirection() != Arcade::Direction::UP)
                        snake.setDirection(Arcade::Direction::DOWN);
                }},
};

void Arcade::Snake::handleEvents(const KeyboardEvents &event)
{
    EventManager::handleEvent(MAP_EVENT, *this, event);
}