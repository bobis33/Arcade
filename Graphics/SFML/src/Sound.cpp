/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sound.cpp
*/

#include <SFML/Audio.hpp>

#include "Arcade/SfmlRenderer.hpp"

void Arcade::SfmlRenderer::stopSound() {
    _sound->stop();
    delete _sound;
}

void Arcade::SfmlRenderer::playSound() {}

void Arcade::SfmlRenderer::loadSound() {
    if (!_buffer.loadFromFile("assets/sounds/menu_sounds.ogg")) {
        std::cerr << "Cannot load sound" << '\n';
    }
    _sound = new sf::Sound();
    _sound->setBuffer(_buffer);
    _sound->play();
    _sound->setVolume(100);
}
