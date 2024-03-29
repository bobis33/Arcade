/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sound.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

void Arcade::Sdl2Renderer::stopSound()
{
    Mix_FreeMusic(_music);
    Mix_CloseAudio();
    Mix_Quit();
}

void Arcade::Sdl2Renderer::playSound() {}

void Arcade::Sdl2Renderer::loadSound()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        throw std::runtime_error("Error initializing SDL_mixer: " + std::string(Mix_GetError()));
    _music = Mix_LoadMUS("assets/sounds/menu_sounds.ogg");
    if (_music == nullptr)
        throw std::runtime_error("Error: " + std::string(Mix_GetError()));
    Mix_PlayMusic(_music, -1);
}