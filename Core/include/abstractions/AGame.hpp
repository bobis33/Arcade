/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame.hpp
*/

/**
 * @file AGame.hpp
 * @brief File declaring Game Abstract class
 */

#pragma once

#ifndef ARCADE_AGAME_HPP
#define ARCADE_AGAME_HPP

#include "IGame.hpp"

namespace Arcade {

    /**
    * @brief Game abstract class
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class AGame : public IGame {
    public:
        ~AGame() override = default;

    }; // AGame

} // Arcade

#endif // ARCADE_AGAME_HPP
