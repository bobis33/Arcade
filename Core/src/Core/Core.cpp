/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::gameLoop()
{
     if (_window->isASCII()) {
         //loadTextures(someasciiartonlyformenu, "ascii art name");
     } else {
         if (!_window->loadFont("assets/fonts/menu_i.ttf", "menu_i"))
             throw std::runtime_error("Cannot load fonts");
         if (!_window->loadTexture("assets/textures/backgrond.jpg", "background"))
             throw std::runtime_error("Cannot load background texture");
         _window->initMenu();
     }

    while (_mode != CoreMode::QUIT) {
        _window->displayWindow();
        handleEvents(_window->getEvent());
        if (_mode == CoreMode::MENU) {
            _window->displayMenu();
        }
        /*if (_mode == CoreMode::GAME) {
         *   _game->update();
         *   _game->display();
         *   }
         */
    }
}
