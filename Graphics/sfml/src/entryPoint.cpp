/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** entryPoint.cpp
*/

#include "Sfml.hpp"

extern "C" {
    std::unique_ptr<Arcade::AGraphic> entryPoint() {
        return std::make_unique<Arcade::Sfml>();
    }
}