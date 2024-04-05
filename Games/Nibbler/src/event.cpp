/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** event
*/

#include "Arcade/Nibbler.hpp"
#include "Arcade/EventsManager.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Nibbler &)>> MAP_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Nibbler &nibbler) -> void {
                    if (nibbler.getDirection() != Arcade::Direction::RIGHT) 
                        nibbler.setDirection(Arcade::Direction::LEFT);
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Nibbler &nibbler) -> void {
                    if (nibbler.getDirection() != Arcade::Direction::LEFT)
                        nibbler.setDirection(Arcade::Direction::RIGHT);
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Nibbler &nibbler) -> void {
                    if (nibbler.getDirection() != Arcade::Direction::DOWN)
                        nibbler.setDirection(Arcade::Direction::UP);
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Nibbler &nibbler) -> void {
                    if (nibbler.getDirection() != Arcade::Direction::UP)
                        nibbler.setDirection(Arcade::Direction::DOWN);
                }},
};

void Arcade::Nibbler::handleEvents(const KeyboardEvents &event)
{
    EventManager::handleEvent<Nibbler>(MAP_EVENT, *this, event);
}