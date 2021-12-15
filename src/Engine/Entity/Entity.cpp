/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Entity
*/

#include "Entity.hpp"

namespace Engine {
    std::string Entity::getName()
    {
        return _name;
    }

    void Entity::unDraw()
    {
        _draw = false;
    }

    bool Entity::canDraw()
    {
        return _draw;
    }

    void Entity::draw()
    {
        _draw = true;
    }

    entityType Entity::getType() const
    {
        return (_type);
    }

    unsigned int Entity::getId() const
    {
        return (_id);
    }

    Entity::Entity(entityType type, std::string name)
    {
        _id = Engine::id + 1;
        _name = name;
        _type = type;
        _draw = false;
        Engine::id += 1;
    }

    Entity::~Entity()
    {
    }
};
