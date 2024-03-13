/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.hpp
*/

#pragma once

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include "abstractions/AGraphic.hpp"

namespace Arcade
{
	class Sfml : public AGraphic
    {
        public:
            Sfml();
            ~Sfml() override = default;

            Sfml(const Sfml &) = delete;
            Sfml &operator=(const Sfml &) = delete;

        private:
            sf::RenderWindow _window;

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
