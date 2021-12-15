/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Grenade
*/

#include "Grenade.hpp"

namespace Engine
{
    Grenade::Grenade(std::string name) : Entity(GRENADE)
    {
        _name = name;
    }

    Grenade::~Grenade()
    {
    }
};