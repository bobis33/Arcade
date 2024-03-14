/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Events.cpp
*/

#include "Sdl2.hpp"

Arcade::GameEvent Arcade::Sdl2::getEvent()
{
    SDL_Event event{};

    while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                SDL_DestroyWindow(_window);
                return Arcade::GameEvent::QUIT;
            case SDL_KEYDOWN:
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

            default:
                return Arcade::GameEvent::NONE;
        }
    }
    return Arcade::GameEvent::NONE;
}
