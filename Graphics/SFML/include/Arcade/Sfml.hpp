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
            ~Sfml() override = default;

            GameEvent getEvent() override;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { _window.display(); };
            void clearWindow() override { _window.clear(); };
            void closeWindow() override { _window.close(); };
            void setTitle(const std::string &title) override { _window.setTitle(title); };

            bool loadTexture(const std::string &texture, const std::string &name) override;
            bool loadFont(const std::string &filepath, const std::string &name) override;
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override;
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
            void displaySprite(const std::string &spriteName) override;
            void displayText(const std::string &textName) override;

            bool isASCII() override { return false; };

        private:
            sf::RenderWindow _window;

            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Sprite> _sprites;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::Text> _texts;

            unsigned int _width{0};
            unsigned int _height{0};

            static GameEvent keyboardEvent(sf::Event event);

    }; // Sfml
}

#endif // ARCADE_SFML_HPP
