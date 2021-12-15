/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** FollowManager
*/

#include "../../../include/Engine/ComponentManager/FollowManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> FollowManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> FollowManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void FollowManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        IComponent *comp = NULL;
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Follow> component(new Follow (comp));
        _mapComponent[ptr] = component;
    }

    FollowManager::FollowManager()
    {
        _mapType[PLAYER] = 1;
        _mapType[ALIEN] = 1;
        _mapType[GRENADE] = 0;
        _mapType[TARGET] = 1;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    FollowManager::~FollowManager()
    {
    }
};