/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "Arcade/NCursesRenderer.hpp"

extern "C" {
    std::unique_ptr<Arcade::IRenderer> entryPoint() {
        return std::make_unique<Arcade::NCursesRenderer>();
    }
}