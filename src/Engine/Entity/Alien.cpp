/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Alien
*/


#include "../../../include/Engine/Entity/Alien.hpp"

namespace Engine
{
    Alien::Alien(std::string name) : Entity(ALIEN)
    {
        _name = name;
    }

    Alien::~Alien()
    {
    }
};