/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Clock.cpp
*/

#include "Arcade/Clock/Clock.hpp"


Arcade::Clock::Clock()
{
    restart();
}

void Arcade::Clock::restart()
{
    m_start = std::chrono::high_resolution_clock::now();
}

Arcade::Time Arcade::Clock::getElapsedTime() const
{
    const auto end{std::chrono::high_resolution_clock::now()};
    const std::chrono::duration<double> elapsed{end - m_start};
    
    return Time(elapsed.count());
}
