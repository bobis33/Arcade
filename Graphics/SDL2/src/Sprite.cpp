/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

bool Arcade::Sdl2Renderer::loadTexture(const std::string &filePath, const std::string &name)
{
    if (_sprites.find(name) != _sprites.end())
        return true;
    SDL_Texture *texture = IMG_LoadTexture(_window.getRenderer(), filePath.c_str());
    if (texture == nullptr)
        return false;
    _sprites[name] = texture;
    return true;
}

void Arcade::Sdl2Renderer::createSprite(const std::string &textureName, const float pos_x, const float pos_y, const float scale_x, const float scale_y)
{
    (void)scale_x;
    (void)scale_y;
    _spritesRect[textureName].x = static_cast<int>(pos_x);
    _spritesRect[textureName].y = static_cast<int>(pos_y);
    _spritesRect[textureName].w = static_cast<int>(_size.first);
    _spritesRect[textureName].h = static_cast<int>(_size.second);
    SDL_QueryTexture(_sprites[textureName], nullptr, nullptr, &_spritesRect[textureName].w, &_spritesRect[textureName].h);
}

void Arcade::Sdl2Renderer::displaySprite(const std::string &spriteName)
{
    SDL_RenderCopy(_window.getRenderer(), _sprites[spriteName], nullptr, &_spritesRect[spriteName]);
}

void Arcade::Sdl2Renderer::moveSprite(const std::string &spriteName, const float pos_x, const float pos_y)
{
    int old_x = _spritesRect[spriteName].x;
    int old_y = _spritesRect[spriteName].y;
    int new_x = old_x + static_cast<int>(pos_x);
    int new_y = old_y + static_cast<int>(pos_y);
    _spritesRect[spriteName].x = new_x;
    _spritesRect[spriteName].y = new_y;
}
