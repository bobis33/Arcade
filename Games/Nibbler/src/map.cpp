/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** map.cpp
*/

#include "Arcade/Nibbler.hpp"

void Arcade::Nibbler::createFood()
{
    size_t food_index = 0;
    std::string food_string{"Sugar"};

    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            if (_mapPositionWall[i][j] == 'o') {
                _mapPositionFood.push_back({{i, j}, true});
                food_index++;
            }
        }
    }
    _nbFood = food_index;
    for (size_t i = 0; i <= _nbFood; i++) {
        food_string = "Sugar";
        food_string += std::to_string(i);
        if (!_renderer->loadTexture("assets/textures/nibbler/sugar.png", food_string))
            throw std::runtime_error("Could not load texture sugar");
        _renderer->createSprite(food_string, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].first, _map[_mapPositionFood[i].first.first][_mapPositionFood[i].first.second].second, 1, 1);
    }
}

void Arcade::Nibbler::createWall()
{
    _mapPositionWall = {
            {' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o', ' ', ' '},
            {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
            {'o', 'X', ' ', 'X', 'o', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'o', 'X', ' ', 'X', 'o'},
            {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
            {' ', ' ', ' ', ' ', ' ', 'X', 'o', 'X', ' ', 'X', 'o', 'X', ' ', ' ', ' ', ' ', ' '},
            {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
            {'o', 'X', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', 'X', 'o'},
            {' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'o', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' '},
            {' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' '},
            {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
            {' ', ' ', 'o', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'o', ' ', ' '},
            {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
            {' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', 'o', ' ', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
            {'o', 'X', 'X', 'X', 'o', 'X', 'o', 'X', 'X', 'X', 'o', 'X', 'o', 'X', 'X', 'X', 'o'},
            {'o', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', 'o'},
            {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
}

void Arcade::Nibbler::createMap()
{
    _map.resize(MAP_HEIGHT);
    for (size_t i = 0; i < MAP_HEIGHT; ++i) {
        _map[i].resize(MAP_WIDTH);
        for (size_t j = 0; j < MAP_WIDTH; ++j) {
            _map[i][j] = {(SIZE_BOX * j) + SIZE_BOX, (SIZE_BOX * i) + SIZE_BOX};
        }
    }
    createWall();
    createFood();
}
