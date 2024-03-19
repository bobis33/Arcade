/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.cpp
*/

#include "Arcade/Sdl2.hpp"

Arcade::Sdl2::Sdl2() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));

    _window = SDL_CreateWindow(WINDOW_TITLE.data(),
                               SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                               1920, 1080,
                               SDL_WINDOW_RESIZABLE);
    if (!_window)
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));

    _renderer = SDL_CreateRenderer(_window, -1,
                                   SDL_RENDERER_ACCELERATED
                                   | SDL_RENDERER_PRESENTVSYNC);
    if (!_renderer)
        throw std::runtime_error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()));
}
