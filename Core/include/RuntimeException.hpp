/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** RuntimeException.hpp
*/

/**
 * @file RuntimeException.hpp
 *
 * @brief File declaring RuntimeException
 */

#pragma once

#ifndef ARCADE_RUNTIME_EXCEPTION_HPP
#define ARCADE_RUNTIME_EXCEPTION_HPP

#include <exception>

namespace Arcade
{
    /**
     * @brief RuntimeException class
     * @details RuntimeException class for the Arcade project
     */

    class RuntimeException : public std::exception
    {
        public:
            explicit RuntimeException(std::string msg) : _msg{std::move(msg)} {}
            ~RuntimeException() override = default;

            RuntimeException(RuntimeException const &) = delete;

            [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); };

        private:
            std::string _msg;

    }; // RuntimeException

} // Arcade

#endif // ARCADE_RUNTIME_EXCEPTION_HPP
