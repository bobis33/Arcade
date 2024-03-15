/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** constants.hpp
*/

/**
 * @file constants.hpp
 *
 * @brief File declaring Constants
 */

#pragma once

#ifndef ARCADE_CONSTANTS_HPP
#define ARCADE_CONSTANTS_HPP

#include <string_view>

/**
 * @brief Constants for the Arcade project
 * @details Set of constants used in the Arcade project
 */

namespace
{
    constexpr int EPITECH_ERROR = 84;
    constexpr int SUCCESS = 0;

    constexpr std::string_view USAGE_MSG = "USAGE\n"
                                     "\t./arcade path\n"
                                     "DESCRIPTION\n"
                                     "\tpath\tPath to the graphical library";

    constexpr std::string_view NO_DISPLAY = "DISPLAY environment variable is not set";
}

#endif // ARCADE_CONSTANTS_HPP
