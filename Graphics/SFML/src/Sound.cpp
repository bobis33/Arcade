/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sound.cpp
*/

#include <SFML/Audio.hpp>

#include "Arcade/SfmlRenderer.hpp"

void Arcade::SfmlRenderer::stopSound() {
    if (_sound == nullptr)
        return;

    _sound->stop();
    delete _sound;
    _sound = nullptr;
}

void Arcade::SfmlRenderer::loadSound() {
    if (!_buffer.loadFromFile("assets/sounds/menu_sounds.ogg")) {
        std::cerr << "Cannot load sound" << '\n';
    }
    _sound = new sf::Sound();
    _sound->setBuffer(_buffer);
    _sound->play();
    _sound->setVolume(100);
}
