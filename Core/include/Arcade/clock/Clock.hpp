/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** clock.hpp
*/

#ifndef ARCADE_SDL2_CLOCK_HPP
#define ARCADE_SDL2_CLOCK_HPP

#include <chrono>

#include "Time.hpp"

namespace Arcade
{
    class Clock
    {
        public:
            /**
             * @brief Construct a new Clock object
             */
            Clock();
            ~Clock() = default;

            /**
             * @brief Restart the clock
             */
            void restart();
            
            /**
             * @brief Get the elapsed time since the last restart
             * 
             * @return Time The elapsed time
             */
            Time getElapsedTime() const;

            /**
             * @brief TimePoint is a type alias for a time point which is a very long and complicated type in the standard library
             */
            using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
        
        private:
            TimePoint m_start;
    };
}

#endif // ARCADE_SDL2_CLOCK_HPP
