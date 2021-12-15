/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Sprite
*/

#include "../../../include/Engine/Entity/Sprite.hpp"

namespace Engine {
    Sprite::Sprite(std::string name) : Entity(SPRITE, name)
    {
        _name = name;
    }

    Sprite::~Sprite()
    {
    }
}