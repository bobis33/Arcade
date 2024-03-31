/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

/*
 * push on the top of the switch cases that will be the most used (and who's implemented too)
 * for optimisation. For example if u put an event at the end of the switch, in every case
 * the program will do the whole switch to reach the last case.
*/

Arcade::KeyboardEvents Arcade::Sdl2Renderer::keyboardEvent(SDL_Event event)
{
    switch(event.key.keysym.sym)
    {
        case SDLK_UP:
            return Arcade::KeyboardEvents::UP;
        case SDLK_DOWN:
            return Arcade::KeyboardEvents::DOWN;
        case SDLK_LEFT:
            return Arcade::KeyboardEvents::LEFT;
        case SDLK_RIGHT:
            return Arcade::KeyboardEvents::RIGHT;
        case SDLK_SPACE:
            return Arcade::KeyboardEvents::CLICK;
        case SDLK_ESCAPE:
            return Arcade::KeyboardEvents::ESC;
        case SDLK_RETURN:
            return Arcade::KeyboardEvents::ENTER;
        case SDLK_F1:
            return Arcade::KeyboardEvents::F1;
        case SDLK_F2:
            return Arcade::KeyboardEvents::F2;

        default:
            return Arcade::KeyboardEvents::NONE;
    }
}

Arcade::KeyboardEvents Arcade::Sdl2Renderer::getEvent()
{
    SDL_Event event{};

    while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                return Arcade::KeyboardEvents::ESC;
            case SDL_KEYDOWN:
                return keyboardEvent(event);

            default:
                return Arcade::KeyboardEvents::NONE;
        }
    }
    return Arcade::KeyboardEvents::NONE;
}
