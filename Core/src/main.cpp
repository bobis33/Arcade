/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include <iostream>

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

constexpr std::string_view USAGE_MSG = "USAGE\n"
                                       "\t./arcade path\n"
                                       "DESCRIPTION\n"
                                       "\tpath\tPath to the graphical library";

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << USAGE_MSG << '\n';
        return EPITECH_ERROR;
    }
    return Arcade::Core().runArcade(argv[1]);
}
