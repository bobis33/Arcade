/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Time.cpp
*/

#include "Arcade/Clock/Clock.hpp"

Arcade::Time::Time(float seconds)
    : m_seconds(seconds){}

int Arcade::Time::asSeconds() const
{
    return static_cast<int>(m_seconds);
}

int Arcade::Time::asMilliseconds() const
{
    return static_cast<int>(m_seconds * 1000);
}

int Arcade::Time::asMicroseconds() const
{
    return static_cast<int>(m_seconds * 1000000);
}
