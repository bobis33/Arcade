/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic.hpp
*/

#pragma once

#ifndef ARCADE_IGRAPHIC_HPP
#define ARCADE_IGRAPHIC_HPP

#include "Enum.hpp"

namespace Arcade {
    class IGraphic {
    public:
        IGraphic() = default;
        virtual ~IGraphic() = default;

        IGraphic(const IGraphic &) = delete;
        IGraphic &operator=(const IGraphic &) = delete;

        virtual GameEvent getEvent() = 0;

        virtual void displayWindow() = 0;
        virtual void clearWindow() = 0;
        virtual void closeWindow() = 0;

    }; // IGraphic

} // Arcade

#endif //ARCADE_IGRAPHIC_HPP
