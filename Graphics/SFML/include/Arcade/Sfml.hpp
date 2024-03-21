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

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include "Arcade/abstractions/IRenderer.hpp"

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

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { _window.display(); };
            void clearWindow() override { _window.clear(); };
            void closeWindow() override { _window.close(); };
            void setTitle(const std::string &title) override { _window.setTitle(title); };
            void displayMenu() override;

        private:
            sf::RenderWindow _window;
            sf::Sprite _sprite;
            sf::Text _text;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::Texture> _textures;

            unsigned int _width{0};
            unsigned int _height{0};

            static GameEvent keyboardEvent(sf::Event event);
            bool loadTexture(const std::string &filepath, const std::string &name);
            bool loadFont(const std::string &filepath, const std::string &name);

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
