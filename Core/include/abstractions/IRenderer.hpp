/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

/**
 * @file IRenderer.hpp
 * @brief File declaring Graphic Interface
 */


#pragma once

#ifndef ARCADE_IRENDERER_HPP
#define ARCADE_IRENDERER_HPP

#include "Enum.hpp"

namespace Arcade {

    /**
     * @brief Graphic Interface
     * @details Set of method to implement for the business logic of the Arcade project
     */
    class IRenderer {
    public:
        IRenderer() = default;
        virtual ~IRenderer() = default;

        IRenderer(const IRenderer &) = delete;
        IRenderer &operator=(const IRenderer &) = delete;

        /**
         * @brief Get the event object
         * @return GameEvent
         */
        virtual GameEvent getEvent() = 0;

        /**
         * @brief display actual window
         */
        virtual void displayWindow() = 0;

        /**
         * @brief clear actual window
         */
        virtual void clearWindow() = 0;

        /**
         * @brief close actual window
         */
        virtual void closeWindow() = 0;

    }; // IRenderer

} // Arcade

#endif //ARCADE_IRENDERER_HPP
