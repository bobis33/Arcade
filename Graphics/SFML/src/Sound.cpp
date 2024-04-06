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



void Arcade::SfmlRenderer::loadSound(const std::string &filePath) {
    if (!_buffer.loadFromFile(filePath)) {
        throw std::runtime_error("Error: Could not load sound file");
    }
    _sound = new sf::Sound();
    _sound->setBuffer(_buffer);
    _sound->setLoop(true);
    _sound->play();
    _sound->setVolume(100);
}
