/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#pragma once

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <iostream>
#include <exception>
#include "Enum.hpp"

namespace Arcade
{

    class Core
    {
        private:
            GameMode _gameMode{GameMode::MENU};
            GameEvent _gameEvent{GameEvent::NONE};

        public:
            Core() = default;
            ~Core() = default;

            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;

            void parser(const std::string &path);

            void gameLoop();
            void handleEvents();

        class CoreException : public std::exception
        {
        public:
            CoreException(const std::string &msg) : _msg{msg} {}
            ~CoreException() override = default;

            const char *what() const noexcept override { return _msg.c_str(); };

        private:
            std::string _msg;

        }; // Exception

    }; // Core

}

#endif // ARCADE_CORE_HPP
