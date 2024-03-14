/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.hpp
*/

#pragma once

#ifndef ARCADE_SDL2_HPP
#define ARCADE_SDL2_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "abstractions/AGraphic.hpp"

namespace Arcade
{
	class Sdl2 : public AGraphic
    {
        public:
            Sdl2();
            ~Sdl2() override = default;

            Sdl2(const Sdl2 &) = delete;
            Sdl2 &operator=(const Sdl2 &) = delete;

            GameEvent getEvent() override;

        private:
            SDL_Window *_window;

    }; // Sdl2

} // Arcade

#endif // ARCADE_SDL2_HPP
