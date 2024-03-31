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
            explicit Time(double seconds);

            /**
             * @brief Transform the time to seconds
             */
            [[nodiscard]] int asSeconds() const;

            /**
             * @brief Transform the time to milliseconds
             */
            [[nodiscard]] int asMilliseconds() const;
            
            /**
             * @brief Transform the time to microseconds
             */
            [[nodiscard]] int asMicroseconds() const;

        private:
            double m_seconds;

    }; // Time

} // namespace Arcade

#endif // ARCADE_TIME_HPP
