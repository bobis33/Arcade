/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** Snake
*/

#include "Arcade/Nibbler.hpp"
#include "Arcade/EventsManager.hpp"

static const std::map<const Arcade::KeyboardEvents, std::function<void(Arcade::Nibbler &)>> MAP_EVENT = {
        {Arcade::KeyboardEvents::LEFT,
                [](Arcade::Nibbler &nibbler) -> void {
                    (void) nibbler;
                }},
        {Arcade::KeyboardEvents::RIGHT,
                [](Arcade::Nibbler &nibbler) -> void {
                    (void) nibbler;
                }},
        {Arcade::KeyboardEvents::UP,
                [](Arcade::Nibbler &nibbler) -> void {
                    (void) nibbler;
                }},
        {Arcade::KeyboardEvents::DOWN,
                [](Arcade::Nibbler &nibbler) -> void {
                    (void) nibbler;
                }},
};

void Arcade::Nibbler::handleEvents(const KeyboardEvents &event)
{
    EventManager::handleEvent(MAP_EVENT, *this, event);
}