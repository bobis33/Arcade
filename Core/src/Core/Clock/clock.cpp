/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Clock.cpp
*/

#include "Arcade/Clock/Clock.hpp"

void Arcade::Clock::pause()
{
    if (!m_paused) {
        m_pause = std::chrono::high_resolution_clock::now();
        m_paused = true;
    }
}

void Arcade::Clock::resume()
{
    if (m_paused) {
        m_start += std::chrono::high_resolution_clock::now() - m_pause;
        m_paused = false;
    }
}

Arcade::Time Arcade::Clock::getElapsedTime() const
{
    TimePoint now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed_time{};
    if (m_paused) {
        elapsed_time = m_pause - m_start;
    } else {
        elapsed_time = now - m_start;
    }
    return Time(elapsed_time.count());
}
