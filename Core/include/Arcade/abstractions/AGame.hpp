/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame.hpp
*/

/**
 * @file AGame.hpp
 * @brief File declaring Game Abstract Class
 */

#ifndef ARCADE_AGAME_HPP
#define ARCADE_AGAME_HPP

#include <random>

#include "Arcade/abstractions/IGame.hpp"

namespace Arcade {

    /**
    * @brief Game Abstract Class
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class AGame : IGame {
        public:
            ~AGame() override = default;

            void start(std::reference_wrapper<IRenderer> renderer, const Clock &clock) override { _renderer = &renderer.get(); _clock = clock; loadGame(); };
            [[nodiscard]] int getScore() const override { return _score; };
            [[nodiscard]] GameMode getGameMode() const override { return _gameMode; };
            [[nodiscard]] Direction getDirection() const override { return _direction; };
            void setDirection(const Direction &direction) override { _direction = direction; };

            int randomize(int min, int max) override {
                std::random_device random_number{};
                std::mt19937 gen(random_number());
                std::uniform_int_distribution<> dis(min, max);
                return dis(gen);
            }

        protected:
            std::vector<std::vector<std::pair<float, float>>> _map{0};
            int _score{0};
            Clock _clock{};
            int _lastMilliseconds{0};
            std::string _userName{""};
            IRenderer *_renderer{nullptr};
            GameMode _gameMode{GameMode::GAME};
            Direction _direction{Direction::RIGHT};
            std::vector<Direction> _prevDirection{0, Direction::NONE};

    }; // AGame

} // namespace Arcade

#endif // ARCADE_AGAME_HPP
