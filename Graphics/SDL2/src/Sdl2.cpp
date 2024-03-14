/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.cpp
*/

#include "Sdl2.hpp"

Arcade::Sdl2::Sdl2() : _window(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));

    _window = SDL_CreateWindow("Arcade - SDL2",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if (!_window)
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));
}

Arcade::GameEvent Arcade::Sdl2::getEvent()
{
    SDL_Event event;

    while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                return Arcade::GameEvent::QUIT;

            default:
                break;
        }
    }
    return Arcade::GameEvent::NONE;
}
