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
    _spritesAngle[textureName] = 0;
    _spritesRect[textureName].w = static_cast<int>(_size.first);
    _spritesRect[textureName].h = static_cast<int>(_size.second);
    SDL_QueryTexture(_sprites[textureName], nullptr, nullptr, &_spritesRect[textureName].w, &_spritesRect[textureName].h);
}

void Arcade::Sdl2Renderer::displaySprite(const std::string &spriteName)
{
    SDL_RenderCopyEx(_window.getRenderer(), _sprites[spriteName], nullptr, &_spritesRect[spriteName], _spritesAngle[spriteName], nullptr, SDL_FLIP_NONE);
}

void Arcade::Sdl2Renderer::moveSprite(const std::string &spriteName, const float pos_x, const float pos_y)
{
    _spritesRect[spriteName].x = static_cast<int>(pos_x);
    _spritesRect[spriteName].y = static_cast<int>(pos_y);
}

void Arcade::Sdl2Renderer::rotateSprite(const std::string &spriteName, float angle) {
    _spritesAngle[spriteName] = angle;
}


/*
std::unique_ptr<Arcade::ISprite> Arcade::Sdl2Window::createSprite(const std::string &textureName, const float pos_x, const float pos_y, const float scale_x, const float scale_y)
{
    return std::make_unique<Arcade::Sdl2Sprite>(textureName, pos_x, pos_y, scale_x, scale_y);
}
*/
