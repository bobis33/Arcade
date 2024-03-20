/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ISprite.hpp
*/

/**
 * @file ISprite.hpp
 * @brief File declaring Sprite Interface
 */

#pragma once

#ifndef ARCADE_ISPRITE_HPP
#define ARCADE_ISPRITE_HPP

#include <string>
#include <vector>

namespace Arcade {

    /**
    * @brief Sprite Interface
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class ISprite {
    public:
        virtual ~ISprite() = default;

        ISprite(const ISprite &) = delete;
        ISprite &operator=(const ISprite &) = delete;

        /**
         * @brief create the sprite
         * @param sprite
         * @details create the sprite with the given sprite, can be a filePath, or a ASCII art
         */
        virtual void createSprite(const std::vector<std::string> &sprite) = 0;

        /**
         * @brief draw the sprite
         */
         virtual void draw() = 0;

        /**
         * @brief set the position of the sprite
         * @param x
         * @param y
         */
         virtual void setPosition(int x, int y) = 0;

    }; // IGame

} // Arcade

#endif // ARCADE_ISPRITE_HPP
