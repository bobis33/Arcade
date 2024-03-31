/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** cursor.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

void Arcade::Core::moveCursorUp() {
    _currentGameIndex = getPreviousLibIndex(_gameLibs, _currentGameIndex);
    _renderer->moveText(">", static_cast<int>(WIDTH * 0.07), static_cast<int>(HEIGHT / 2 - 110 + 50 * (_currentGameIndex + 1)));
}

void Arcade::Core::moveCursorDown()
{
    _currentGameIndex = getNextLibIndex(_gameLibs, _currentGameIndex);
    _renderer->moveText(">", static_cast<int>(WIDTH * 0.07),static_cast<int>(HEIGHT / 2 - 110 + 50 * (_currentGameIndex + 1)));
}
