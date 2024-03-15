/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGraphic.hpp
*/

/**
 * @file AGraphic.hpp
 * @brief File declaring Graphic Abstract class
 */

#pragma once

#ifndef ARCADE_AGRAPHIC_HPP
#define ARCADE_AGRAPHIC_HPP

#include "IGraphic.hpp"

namespace Arcade {

    /**
    * @brief Graphic abstract class
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class AGraphic : public IGraphic {
    public:
        AGraphic() = default;
        ~AGraphic() override = default;

        AGraphic(const AGraphic &) = delete;
        AGraphic &operator=(const AGraphic &) = delete;

    }; // AGraphic

} // Arcade

#endif //ARCADE_AGRAPHIC_HPP
