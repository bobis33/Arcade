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
#include "Arcade/abstractions/IRenderer.hpp"

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
            void setTitle(const std::string &title) override { _window.setTitle(title); };
            void displayMenu() override;

        private:
            sf::RenderWindow _window;
            sf::Font _font;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Text _text;

            static GameEvent keyboardEvent(sf::Event event);

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
