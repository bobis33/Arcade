/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic.hpp
*/

/**
 * @file IGraphic.hpp
 * @brief File declaring Graphic Interface
 */


#pragma once

#ifndef ARCADE_IGRAPHIC_HPP
#define ARCADE_IGRAPHIC_HPP

#include "Enum.hpp"

namespace Arcade {

    /**
     * @brief Graphic Interface
     * @details Set of method to implement for the business logic of the Arcade project
     */
    class IGraphic {
    public:
        IGraphic() = default;
        virtual ~IGraphic() = default;

        IGraphic(const IGraphic &) = delete;
        IGraphic &operator=(const IGraphic &) = delete;

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

    }; // IGraphic

} // Arcade

#endif //ARCADE_IGRAPHIC_HPP
