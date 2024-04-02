/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Event.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

Arcade::KeyboardEvents Arcade::Sdl2Renderer::keyboardEvent(SDL_Event event)
{
    const char *scancodeName = SDL_GetScancodeName(event.key.keysym.scancode);

    if (scancodeName != nullptr && strlen(scancodeName) == 1 && isprint(scancodeName[0])) {
        const char str[2] = {scancodeName[0], '\0'};
        strcat(_input, str);
        return Arcade::KeyboardEvents::TEXTENTERED;
    }

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
