/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** HealthManager
*/

#include "../../../include/Engine/ComponentManager/HealthManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> HealthManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> HealthManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void HealthManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Health> component(new Health(0));
        _mapComponent[ptr] = component;
    }

    HealthManager::HealthManager()
    {
        _mapType[PLAYER] = 1;
        _mapType[ALIEN] = 1;
        _mapType[GRENADE] = 0;
        _mapType[TARGET] = 0;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    HealthManager::~HealthManager()
    {
    }
};