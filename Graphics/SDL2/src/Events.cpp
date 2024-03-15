/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Events.cpp
*/

#include "Sdl2.hpp"

/*
 * push on the top of the switch cases that will be the most used (and who's implemented too)
 * for optimisation. For example if u put an event at the end of the switch, in every case
 * the program will do the whole switch to reach the last case.
*/

Arcade::GameEvent Arcade::Sdl2::keyboardEvent(SDL_Event event)
{
    switch(event.key.keysym.sym)
    {
        case SDLK_UP:
            return Arcade::GameEvent::UP;
        case SDLK_DOWN:
            return Arcade::GameEvent::DOWN;
        case SDLK_LEFT:
            return Arcade::GameEvent::LEFT;
        case SDLK_RIGHT:
            return Arcade::GameEvent::RIGHT;
        case SDLK_SPACE:
            return Arcade::GameEvent::SHOOT;
        case SDLK_ESCAPE:
            return Arcade::GameEvent::PAUSE;

        default:
            return Arcade::GameEvent::NONE;
    }
}

Arcade::GameEvent Arcade::Sdl2::getEvent()
{
    SDL_Event event{};

    while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                return Arcade::GameEvent::QUIT;
            case SDL_KEYDOWN:
                return keyboardEvent(event);

            default:
                return Arcade::GameEvent::NONE;
        }
    }
    return Arcade::GameEvent::NONE;
}
