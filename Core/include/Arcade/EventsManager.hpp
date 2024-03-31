/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** EventsManager.hpp
*/

/**
 * @file EventsManager.hpp
 * @brief File declaring EventsManager
 */

#ifndef ARCADE_EVENTS_MANAGER_HPP
#define ARCADE_EVENTS_MANAGER_HPP

#include <map>
#include <functional>

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"

/**
 * @namespace Arcade
 * @brief Main namespace for the Arcade project
 */

namespace Arcade
{
    /**
     * @brief EventManager class
     * @details EventManager class for the Arcade project
     */
    class EventManager {
    public:
        template<typename T>
        static void handleEvent(const std::map<const Arcade::KeyboardEvents, std::function<void(T&)>>& eventMap, T& object, const Arcade::KeyboardEvents& event)
        {
            auto map_event = eventMap.find(event);

            if (map_event != eventMap.end())
                map_event->second(object);
        }

    }; // EventManager

} // namespace Arcade

#endif // ARCADE_EVENTS_MANAGER_HPP