/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** entryPoint.cpp
*/

#include "Sfml.hpp"

extern "C" {
std::unique_ptr<Arcade::AGraphic> entryPoint() {
    std::unique_ptr<Arcade::Sfml> sfml = std::make_unique<Arcade::Sfml>();
    return sfml->openWindow();
}
}