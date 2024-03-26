/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2Window.cpp
*/

#include "Arcade/Sdl2Window.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SDL2";

void Arcade::Sdl2Window::closeWindow() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Arcade::Sdl2Window::openWindow(unsigned int width, unsigned int height) {
    _widht = static_cast<int>(width);
    _height = static_cast<int>(height);
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));
    }

    _window = SDL_CreateWindow(WINDOW_TITLE.data(),
                               SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                               _widht, _height,
                               SDL_WINDOW_RESIZABLE);
    if (_window == nullptr) {
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));
    }

    _renderer = SDL_CreateRenderer(_window, -1,
                                   SDL_RENDERER_ACCELERATED
                                   | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) {
        throw std::runtime_error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()));
    }
}
