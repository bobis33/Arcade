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
#include <memory>
#include <utility>
#include "Enum.hpp"
#include "abstractions/AGraphic.hpp"

namespace Arcade
{
    class Core
    {
        private:
            CoreMode _coreMode{CoreMode::MENU};
            std::unique_ptr<AGraphic> _graphicLib{nullptr};
            GameEvent _event{GameEvent::NONE};

        public:
            Core() = default;
            ~Core() = default;

            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;

            void parser(const std::string &path);

            void gameLoop();
            void handleEvents();
            void setMode(CoreMode gameMode) { _coreMode = gameMode; };

        class CoreException : public std::exception
        {
            public:
                explicit CoreException(std::string msg) : _msg{std::move(msg)} {}
                ~CoreException() override = default;

                [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); };

            private:
                std::string _msg;

        }; // Exception

    }; // Core

} // Arcade

#endif // ARCADE_CORE_HPP
