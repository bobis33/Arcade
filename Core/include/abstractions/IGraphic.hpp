/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic.hpp
*/

#pragma once

#ifndef ARCADE_IGRAPHIC_HPP
#define ARCADE_IGRAPHIC_HPP

namespace Arcade {
    class IGraphic {
    public:
        virtual ~IGraphic() = default;

        IGraphic(const IGraphic &) = delete;
        IGraphic &operator=(const IGraphic &) = delete;

        virtual void openWindow() = 0;
        virtual void closeWindow() = 0;
        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;
    }; // IGraphic
} // Arcade

#endif //ARCADE_IGRAPHIC_HPP
