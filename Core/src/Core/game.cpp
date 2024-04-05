/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** game.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

void Arcade::Core::launchGame()
{
    Clock clock{};

    switchLib<IGame>(LIB_PATH + _gameLibs[_currentGameIndex]);
    _renderer->getWindow()->clearWindow();
    _renderer->loadSound("assets/sounds/game.ogg");
    _game->getUserName(_userName);
    _game->start(std::reference_wrapper<IRenderer>(*_renderer), clock);
}
