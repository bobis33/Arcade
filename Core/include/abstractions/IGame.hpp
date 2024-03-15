/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGame.hpp
*/

/**
 * @file IGame.hpp
 * @brief File declaring Game Interface
 */

#pragma once

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

namespace Arcade {

    /**
    * @brief Game Interface
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class IGame {
    public:
        virtual ~IGame() = default;

        IGame(const IGame &) = delete;
        IGame &operator=(const IGame &) = delete;

    }; // IGame

} // Arcade

#endif // ARCADE_IGAME_HPP
