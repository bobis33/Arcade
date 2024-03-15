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
#include "Enum.hpp"
#include "abstractions/AGraphic.hpp"

namespace Arcade
{
    class Core
    {
        private:
            CoreMode _mode{CoreMode::MENU};
            std::unique_ptr<AGraphic> _window{nullptr};

        public:
            Core() = default;
            ~Core() = default;

            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;

            void parser(const std::string &path);
            int runArcade(const std::string &path);

            void gameLoop();
            void handleEvents(GameEvent event);

            void setMode(CoreMode gameMode) { _mode = gameMode; };
            void closeWindow() { _window->closeWindow(); };

        class CoreException : public std::exception
        {
            public:
                explicit CoreException(std::string msg) : _msg{std::move(msg)} {}
                ~CoreException() override = default;

                CoreException(CoreException const &) = delete;

            [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); };

            private:
                std::string _msg;

        }; // Exception

    }; // Core

} // Arcade

#endif // ARCADE_CORE_HPP
