/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** time.hpp
*/

#ifndef ARCADE_TIME_HPP
#define ARCADE_TIME_HPP

namespace Arcade
{
    class Time
    {
        public:
            /**
             * @brief Construct a new Time object
             */
            explicit Time(double seconds) : m_seconds(seconds) {};

            /**
             * @brief Transform the time to seconds
             */
            [[nodiscard]] int asSeconds() const { return static_cast<int>(m_seconds); };

            /**
             * @brief Transform the time to milliseconds
             */
            [[nodiscard]] int asMilliseconds() const { return static_cast<int>(m_seconds * 1000); }
            
            /**
             * @brief Transform the time to microseconds
             */
            [[nodiscard]] int asMicroseconds() const { return static_cast<int>(m_seconds * 1000000); };

        private:
            double m_seconds{0.0F};

    }; // Time

} // namespace Arcade

#endif // ARCADE_TIME_HPP
