/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** constants.hpp
*/

#pragma once

#ifndef ARCADE_CONSTANTS_HPP
#define ARCADE_CONSTANTS_HPP

#include <string_view>

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
