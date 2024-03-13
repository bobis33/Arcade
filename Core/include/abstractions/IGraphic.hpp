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
        IGraphic() = default;
        virtual ~IGraphic() = default;

        IGraphic(const IGraphic &) = delete;
        IGraphic &operator=(const IGraphic &) = delete;

    }; // IGraphic

} // Arcade

#endif //ARCADE_IGRAPHIC_HPP
