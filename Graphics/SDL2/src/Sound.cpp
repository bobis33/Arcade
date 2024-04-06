/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sound.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

void Arcade::Sdl2Renderer::loadSound(const std::string &filePath)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        throw std::runtime_error("Error initializing SDL_mixer: " + std::string(Mix_GetError()));
    _music = Mix_LoadMUS(filePath.c_str());
    Mix_PlayMusic(_music, -1);
}

void Arcade::Sdl2Renderer::stopSound()
{
    if (_music == nullptr)
        return;

    Mix_FreeMusic(_music);
    Mix_CloseAudio();
    Mix_Quit();
    _music = nullptr;
}
