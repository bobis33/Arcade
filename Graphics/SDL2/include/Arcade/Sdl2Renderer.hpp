/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2Renderer.hpp
*/

/**
 * @file Sdl2Renderer.hpp
 * @brief File declaring Sdl2Renderer class
 */

#ifndef ARCADE_SDL2_RENDERER_HPP
#define ARCADE_SDL2_RENDERER_HPP

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Sdl2Window.hpp"

namespace Arcade
{

    /**
    * @brief Sdl2Renderer class
    * @details Sdl2Renderer class for the Arcade project
    */
	class Sdl2Renderer : public IRenderer
    {
        public:
            ~Sdl2Renderer() override = default;

            KeyboardEvents getEvent() override;

            bool loadTexture(const std::string &filePath, const std::string &name) override;
            bool loadFont(const std::string &filepath, const std::string &name) override;
            void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override;
            void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
            void displaySprite(const std::string &spriteName) override;
            void displayText(const std::string &textName) override;
            void moveText(const std::string &textName, int pos_x, int pos_y) override;

            bool isASCII() override { return false; };

            IWindow *getWindow() override { return &_window; };

            void loadSound() override;
            void stopSound() override;

        private:

            /**
             * @brief The Sdl2Window
             */
            Sdl2Window _window;

            /**
             * @brief The sprites
             */
            std::map<std::string, SDL_Texture *> _sprites;

            /**
             * @brief The fonts
             */
            std::map<std::string, TTF_Font *> _fonts;

            /**
             * @brief The texts
             */
            std::map<std::string, SDL_Texture *> _texts;

            /**
             * @brief The texts sizes
             */
            std::map<std::string, SDL_Rect> _textsRect;

            /**
             * @brief The sprites sizes
             */
            std::map<std::string, SDL_Rect> _spritesRect;

            /**
             * @brief The music
             */
            Mix_Music *_music;

            /**
             * @brief Get the keyboard event
             * @param event The SDL event
             * @return The game event
             */
            static KeyboardEvents keyboardEvent(SDL_Event event);

    }; // Sdl2Renderer

} // namespace Arcade

#endif // ARCADE_SDL2_RENDERER_HPP
