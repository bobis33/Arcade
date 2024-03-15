/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"
#include "Constants.hpp"

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << USAGE_MSG << std::endl;
        return EPITECH_ERROR;
    }
    return Arcade::Core().runArcade(argv[1]);
}