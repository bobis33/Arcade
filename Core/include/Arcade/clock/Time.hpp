/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** time.hpp
*/

#ifndef ARCADE_SDL2_TIME_HPP
#define ARCADE_SDL2_TIME_HPP


namespace Arcade
{
    class Time
    {
        public:
            /**
             * @brief Construct a new Time object
             */
            explicit Time(float seconds);

            /**
             * @brief Transform the time to seconds
             */
            int asSeconds() const;

            /**
             * @brief Transform the time to milliseconds
             */
            int asMilliseconds() const;
            
            /**
             * @brief Transform the time to microseconds
             */
            int asMicroseconds() const;

        private:
            float m_seconds;
    };
}

#endif // ARCADE_SDL2_TIME_HPP
