/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Follow
*/

#include "../../../include/Engine/Component/Follow.hpp"

Engine::Follow::Follow(IComponent *component)
{
    _component = component;
}

void Engine::Follow::setComponent(IComponent *component)
{
    _component = component;
}

Engine::IComponent *Engine::Follow::getComponent() const
{
    return (_component);
}

Engine::Follow::~Follow()
{
}
