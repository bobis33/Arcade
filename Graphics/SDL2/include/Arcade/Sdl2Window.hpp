/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2Window.hpp
*/

/**
 * @file Sdl2Window.hpp
 * @brief File declaring Sdl2Window class
 */

#ifndef ARCADE_SDL2_WINDOW_HPP
#define ARCADE_SDL2_WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Arcade/abstractions/IWindow.hpp"

namespace Arcade
{

    /**
    * @brief Sdl2Window class
    * @details Sdl2Window class for the Arcade project
    */
	class Sdl2Window : public IWindow
    {
        public:
            ~Sdl2Window() override = default;

            void openWindow(unsigned int width, unsigned int height) override;
            void displayWindow() override { SDL_RenderPresent(_renderer); };
            void clearWindow() override { SDL_RenderClear(_renderer); };
            void closeWindow() override;
            void setTitle(const std::string &title) override { SDL_SetWindowTitle(_window, title.c_str()); };

            /**
             * @brief Get the current window
             * @return The current window
             */
            SDL_Window *getWindow() { return _window; };

            /**
             * @brief Get the current renderer
             * @return The current renderer
             */
            SDL_Renderer *getRenderer() { return _renderer; };

            /**
             * @brief Get the width of the window
             * @return The width of the window
             */
            [[nodiscard]] int getWidth() const { return _widht; };

            /**
             * @brief Get the height of the window
             * @return The height of the window
             */
            [[nodiscard]] int getHeight() const { return _height; };

        private:

            /**
             * @brief The SDL window
             */
            SDL_Window *_window{nullptr};

            /**
             * @brief The SDL renderer
             */
            SDL_Renderer *_renderer{nullptr};

            /**
             * @brief The width of the window
             */
            int _widht{0};

            /**
             * @brief The height of the window
             */
            int _height{0};

    }; // Sdl2Window

} // namespace Arcade

#endif // ARCADE_SDL2_WINDOW_HPP
