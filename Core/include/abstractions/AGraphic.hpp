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
        AGraphic() = default;
        ~AGraphic() override = default;

        AGraphic(const AGraphic &) = delete;
        AGraphic &operator=(const AGraphic &) = delete;

    }; // AGraphic

} // Arcade

#endif //ARCADE_AGRAPHIC_HPP
