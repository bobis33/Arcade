/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite.cpp
*/

#include "Arcade/SfmlRenderer.hpp"

bool Arcade::SfmlRenderer::loadTexture(const std::string &filePath, const std::string &name)
{
    return (_textures[name].loadFromFile(filePath));
}

void Arcade::SfmlRenderer::createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y)
{
    _sprites[textureName].setTexture(_textures[textureName]);
    _sprites[textureName].setPosition(pos_x, pos_y);
    _sprites[textureName].setScale(scale_x, scale_y);
}

void Arcade::SfmlRenderer::displaySprite(const std::string &spriteName)
{
    _window.getWindow()->draw(_sprites[spriteName]);
}

void Arcade::SfmlRenderer::moveSprite(const std::string &spriteName, float pos_x, float pos_y) {
    _sprites[spriteName].setPosition(pos_x, pos_y);
}

void Arcade::SfmlRenderer::rotateSprite(const std::string &spriteName, float angle) {
    float sizeX = 0;
    float sizeY = 0;

    _sprites[spriteName].setRotation(angle);
    if (angle == 90) {
        sizeX = static_cast<float>(_textures[spriteName].getSize().x);
        sizeY = 0;
    } else if (angle == 180) {
        sizeX = static_cast<float>(_textures[spriteName].getSize().x);
        sizeY = static_cast<float>(_textures[spriteName].getSize().y);
    } else if (angle == 270) {
        sizeX = 0;
        sizeY = static_cast<float>(_textures[spriteName].getSize().y);
    } else {
        sizeX = 0;
        sizeY = 0;
    }
    moveSprite(spriteName, _sprites[spriteName].getPosition().x + sizeX, _sprites[spriteName].getPosition().y + sizeY);

}
