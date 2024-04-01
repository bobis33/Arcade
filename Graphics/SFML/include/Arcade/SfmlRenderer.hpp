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
#include <SFML/Audio.hpp>

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

            bool loadFont(const std::string &filepath, const std::string &name) override;
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
            void moveText(const std::string &textName, int pos_x, int pos_y) override;
            void displayText(const std::string &textName) override;

            bool loadTexture(const std::string &texture, const std::string &name) override;
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override;
            void displaySprite(const std::string &spriteName) override;

            std::string updateTextBox() override;

            void loadSound() override;
            void stopSound() override;

            IWindow *getWindow() override { return &_window; };
            KeyboardEvents getEvent() override;

            bool isASCII() override { return false; };
            void setSize(float x, float y) override { _size = std::make_pair(x, y); };

            /**
             * @brief Set the Input object
             * @details used for username input
             *
             * @param event The event to set
             */
            void setInput(const sf::Event &event);


        private:
            SfmlWindow _window;
            sf::SoundBuffer _buffer;
            sf::Sound* _sound;
            std::string _input;
            std::pair<float, float> _size;

            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Sprite> _sprites;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::Text> _texts;

            static KeyboardEvents keyboardEvent(const sf::Event &event);

    }; // SfmlRenderer

} // namespace Arcade

#endif // ARCADE_SFML_RENDERER_HPP
