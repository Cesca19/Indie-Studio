/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Player
*/

#include "../../../include/Engine/Entity/Player.hpp"

namespace Engine
{
    Player::Player(std::string name) : Entity(PLAYER)
    {
        _name = name;
    }

    Player::~Player()
    {
    }
};