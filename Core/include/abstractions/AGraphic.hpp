/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGraphic.hpp
*/

#pragma once

#ifndef ARCADE_AGRAPHIC_HPP
#define ARCADE_AGRAPHIC_HPP

#include "IGraphic.hpp"

namespace Arcade {
    class AGraphic : public IGraphic {
    public:
        virtual ~AGraphic() override = default;

        void openWindow() override;
        void closeWindow() override;
        void clearWindow() override;
        void displayWindow() override;
    }; // AGraphic
} // Arcade

#endif //ARCADE_AGRAPHIC_HPP
