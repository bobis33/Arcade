/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** game.cpp
*/


#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

void Arcade::Core::launchGame()
{
    switchLib<IGame>(LIB_PATH + _gameLibs[_currentGameIndex]);
    _renderer->getWindow()->clearWindow();
}
