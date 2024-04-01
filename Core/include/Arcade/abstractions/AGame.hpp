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

#include "Arcade/abstractions/IGame.hpp"

namespace Arcade {

    /**
    * @brief Game Abstract Class
    * @details Set of method to implement for the business logic of the Arcade project
    */
    class AGame : IGame {
        public:
            ~AGame() override = default;

            void start(std::reference_wrapper<IRenderer> renderer, Clock &clock) override { _renderer = &renderer.get(); _clock = clock; loadGame(); };
            [[nodiscard]] int getScore() const override { return _score; };
            [[nodiscard]] GameMode getGameMode() const override { return _gameMode; };
            Direction getDirection() const override { return _direction; };
            void setDirection(Direction direction) override { _direction = direction; };

        protected:
            int _score{0};
            Clock _clock;
            int _lastSecond{0};
            IRenderer *_renderer{nullptr};
            GameMode _gameMode{GameMode::GAME};
            Direction _direction{Direction::RIGHT};

    }; // AGame

} // namespace Arcade

#endif // ARCADE_AGAME_HPP
