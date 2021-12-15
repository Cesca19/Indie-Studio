/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** CollisionManager
*/

#include "../../../include/Engine/ComponentManager/CollisionManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> CollisionManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> CollisionManager::getAllEntity()
    {
        return (_entityArray);
    }

    void CollisionManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        entityType type = ptr->getType();
        if (!_mapType[type])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Collision> component(new Collision(0, 0));
        _mapComponent[ptr] = component;
    }

    CollisionManager::CollisionManager()
    {
        _mapType[PLAYER] = 1;
        _mapType[ALIEN] = 1;
        _mapType[GRENADE] = 1;
        _mapType[TARGET] = 1;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    CollisionManager::~CollisionManager()
    {
    }
};