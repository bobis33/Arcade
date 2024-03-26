/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite.cpp
*/

#include "Arcade/SfmlRenderer.hpp"

bool Arcade::SfmlRenderer::loadTexture(const std::string &filePath, const std::string &name) {
    return _textures[name].loadFromFile(filePath);
}

void Arcade::SfmlRenderer::createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x,
                                        float scale_y) {
    _sprites[textureName].setTexture(_textures[textureName]);
    _sprites[textureName].setPosition(pos_x, pos_y);
    _sprites[textureName].setScale(scale_x, scale_y);
}

void Arcade::SfmlRenderer::displaySprite(const std::string &spriteName) {
    _window.getWindow()->draw(_sprites[spriteName]);
}

/*
bool Arcade::SfmlSprite::loadTexture(const std::string &filePath, const std::string &name) {
    return _textures[name].loadFromFile(filePath);
}

void Arcade::SfmlSprite::draw(sf::RenderWindow &window) {
    window.draw(_sprite);
}

Arcade::SfmlSprite::SfmlSprite(const std::string &string, const float pos_x, const float pos_y, float scale_x, float scale_y)
{
    _sprite.setTexture(_textures[string]);
    _sprite.setPosition(pos_x, pos_y);
    _sprite.setScale(scale_x, scale_y);
}
 */
