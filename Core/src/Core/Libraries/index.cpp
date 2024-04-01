/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** index.cpp
*/

#include "Arcade/Core.hpp"

size_t Arcade::Core::getPreviousLibIndex(std::vector<std::string> &libs, size_t index)
{
    size_t tmpIndex = 0;

    if (index == 0) {
        tmpIndex = libs.size() - 1;
    } else {
        tmpIndex = index - 1;
    }
    return tmpIndex;
}

size_t Arcade::Core::getNextLibIndex(std::vector<std::string> &libs, size_t currentIndex)
{
    for (size_t index = 0; index < libs.size(); index++) {
        if (libs[index] == libs[currentIndex]) {
            currentIndex = index;
        }
    }
    return (currentIndex + 1) % libs.size();
}
