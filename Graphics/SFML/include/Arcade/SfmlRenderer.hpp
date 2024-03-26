/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SfmlRenderer.hpp
*/

/**
 * @file SfmlRenderer.hpp
 * @brief File declaring SfmlRenderer class
 */

#ifndef ARCADE_SFML_RENDERER_HPP
#define ARCADE_SFML_RENDERER_HPP

#include <SFML/Graphics.hpp>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/abstractions/IWindow.hpp"
#include "Arcade/SfmlWindow.hpp"

namespace Arcade
{

    /**
    * @brief SfmlRenderer class
    * @details SfmlRenderer class for the Arcade project
    */
	class SfmlRenderer : public IRenderer
    {
        public:
            ~SfmlRenderer() override = default;

            GameEvent getEvent() override;

            bool loadTexture(const std::string &texture, const std::string &name) override;
            bool loadFont(const std::string &filepath, const std::string &name) override;
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override;
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
            void displaySprite(const std::string &spriteName) override;
            void displayText(const std::string &textName) override;

            bool isASCII() override { return false; };

            IWindow *getWindow() override { return &_window; };

        private:
            SfmlWindow _window;

            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Sprite> _sprites;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::Text> _texts;

            unsigned int _width{0};
            unsigned int _height{0};

            static GameEvent keyboardEvent(sf::Event event);

    }; // SfmlRenderer

} // namespace Arcade

#endif // ARCADE_SFML_RENDERER_HPP
