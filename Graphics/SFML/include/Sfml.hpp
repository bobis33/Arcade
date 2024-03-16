/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml.hpp
*/

/**
 * @file Sfml.hpp
 * @brief File declaring Sfml class
 */

#pragma once

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include "abstractions/IRenderer.hpp"

constexpr std::string_view WINDOW_TITLE = "Arcade - SFML";

namespace Arcade
{

    /**
    * @brief Sfml class
    * @details Sfml class for the Arcade project
    */
	class Sfml : public IRenderer
    {
        public:
            Sfml();
            ~Sfml() override = default;

            Sfml(const Sfml &) = delete;
            Sfml &operator=(const Sfml &) = delete;

            GameEvent getEvent() override;

            void displayWindow() override { _window.display(); };
            void clearWindow() override { _window.clear(); };
            void closeWindow() override { _window.close(); };

        private:
            sf::RenderWindow _window;

            static GameEvent keyboardEvent(sf::Event event);

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
