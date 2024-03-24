/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite.cpp
*/

#include <SDL2/SDL_image.h>

#include "Arcade/Sdl2.hpp"

bool Arcade::Sdl2::loadTexture(const std::string &filePath, const std::string &name)
{
    if (_textures.find(name) != _textures.end())
        return true;
    SDL_Texture *texture = IMG_LoadTexture(_renderer, filePath.c_str());
    if (texture == nullptr)
        return false;
    _textures[name] = texture;
    return true;
}

void Arcade::Sdl2::createSprite(const std::string &textureName, const float pos_x, const float pos_y, const float scale_x, const float scale_y)
{
    (void)scale_x;
    (void)scale_y;
    _spritesRect[textureName].x = static_cast<int>(pos_x);
    _spritesRect[textureName].y = static_cast<int>(pos_y);
    _spritesRect[textureName].w = _widht;
    _spritesRect[textureName].h = _height;
}

void Arcade::Sdl2::displaySprite(const std::string &spriteName)
{
    SDL_RenderCopy(_renderer, _textures[spriteName], nullptr, &_spritesRect[spriteName]);
}

/*
std::unique_ptr<Arcade::ISprite> Arcade::Sdl2::createSprite(const std::string &textureName, const float pos_x, const float pos_y, const float scale_x, const float scale_y)
{
    return std::make_unique<Arcade::Sdl2Sprite>(textureName, pos_x, pos_y, scale_x, scale_y);
}
*/