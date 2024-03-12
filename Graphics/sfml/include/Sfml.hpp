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
            Sfml() = default;
            ~Sfml() override = default;

            Sfml(const Sfml &) = delete;
            Sfml &operator=(const Sfml &) = delete;

            void openWindow() override final;
            void closeWindow() override final;
            void clearWindow() override final;
            void displayWindow() override final;

        private:
            sf::RenderWindow _window;
            std::string _name;

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
