/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"
#include "Constants.hpp"

static int runArcade(const std::string& path)
{
    Arcade::Core core;

    try {
        if (!getenv("DISPLAY"))
            throw Arcade::Core::CoreException{NO_DISPLAY.data()};
        core.parser(path);
        core.gameLoop();
    } catch (Arcade::Core::CoreException& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return EPITECH_ERROR;
    }
    return EPITECH_SUCCESS;
}

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << USAGE_MSG << '\n';
        return EPITECH_ERROR;
    }
    return runArcade(argv[1]);
}