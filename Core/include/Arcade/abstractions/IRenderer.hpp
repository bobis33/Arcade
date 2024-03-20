/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

/**
 * @file IRenderer.hpp
 * @brief File declaring Graphic Interface
 */


#ifndef ARCADE_IRENDERER_HPP
#define ARCADE_IRENDERER_HPP

#include <string>

#include "Arcade/Enum.hpp"

namespace Arcade {

    /**
     * @brief Graphic Interface
     * @details Set of method for the Arcade project
     */
    class IRenderer {
    public:
        virtual ~IRenderer() = default;

        /**
         * @brief Create a window with the specified dimensions
         * @param width The width of the window
         * @param height The height of the window
         */
        virtual void openWindow(unsigned int width, unsigned int height) = 0;

        /**
         * @brief Display the current window
         */
        virtual void displayWindow() = 0;

        /**
         * @brief Clear the contents of the current window
         */
        virtual void clearWindow() = 0;

        /**
         * @brief Close the current window
         */
        virtual void closeWindow() = 0;

        /**
         * @brief Set the title of the window
         * @param title The new title of the window
         */
        virtual void setTitle(const std::string &title) = 0;

        /**
         * @brief Retrieve the current event from the window
         * @return The current event
         */
        virtual GameEvent getEvent() = 0;

        /**
         * @brief Check if the renderer supports only ASCII characters
         * @return True if the renderer supports ASCII, false otherwise
         */
        virtual bool isASCII() = 0;

        /**
         * @brief Load a texture from a file
         * @param filepath The path to the texture file
         * @param name The name to associate with the texture
         * @return True if the texture was loaded successfully, false otherwise
         */
        virtual bool loadTexture(const std::string &filepath, const std::string &name) = 0;

        /**
         * @brief Load a font from a file
         * @param filepath The path to the font file
         * @param name The name to associate with the font
         * @return True if the font was loaded successfully, false otherwise
         */
        virtual bool loadFont(const std::string &filepath, const std::string &name) = 0;

        /**
         * @brief Create a sprite with the specified parameters
         * @param textureName The name of the texture to use for the sprite
         * @param pos_x The x-coordinate of the sprite's position
         * @param pos_y The y-coordinate of the sprite's position
         * @param scale_x The scale factor for the sprite's width
         * @param scale_y The scale factor for the sprite's height
         */
        virtual void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) = 0;

        /**
         * @brief Display a sprite with the specified name
         * @param spriteName The name of the sprite to display
         */
        virtual void displaySprite(const std::string &spriteName) = 0;

        /**
         * @brief Create a text object with the specified parameters
         * @param fontName The name of the font to use for the text
         * @param text The text to display
         * @param size The size of the text
         * @param pos_x The x-coordinate of the text's position
         * @param pos_y The y-coordinate of the text's position
         */
        virtual void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) = 0;

        /**
         * @brief Display a text object with the specified name
         * @param textName The name of the text to display
         */
        virtual void displayText(const std::string &textName) = 0;

    }; // IRenderer

} // namespace Arcade

#endif // ARCADE_IRENDERER_HPP
