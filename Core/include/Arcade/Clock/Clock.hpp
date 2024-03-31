/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Clock.hpp
*/

#ifndef ARCADE_CLOCK_HPP
#define ARCADE_CLOCK_HPP

#include <chrono>

#include "Arcade/Clock/Time.hpp"

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
            [[nodiscard]] Time getElapsedTime() const;

            /**
             * @brief TimePoint is a type alias for a time point which is a very long and complicated type in the standard library
             */
            using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
        
        private:
            TimePoint m_start;

    }; // Clock

} // namespace Arcade

#endif // ARCADE_CLOCK_HPP
