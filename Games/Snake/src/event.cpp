/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Snake.hpp"
#include "Arcade/EventsManager.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Snake &)>> MAP_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Snake &snake) -> void {
                    (void) snake;
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Snake &snake) -> void {
                    (void) snake;
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Snake &snake) -> void {
                    (void) snake;
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Snake &snake) -> void {
                    (void) snake;
                }},
};


void Arcade::Snake::handleEvents(KeyboardEvents event)
{
    EventManager::handleEvent(MAP_EVENT, *this, event);
}