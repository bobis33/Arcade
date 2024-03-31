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
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(now - m_start);
    
    return Time(static_cast<float>(elapsed.count()));
}
