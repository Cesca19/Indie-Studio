/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MotionManager
*/

#include "MotionManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> MotionManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> MotionManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void MotionManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Motion> component(new Motion(0, 0, 0, 0));
        _mapComponent[ptr] = component;
    }

    MotionManager::MotionManager()
    {
        _mapType[PLAYER] = 1;
        _mapType[ALIEN] = 1;
        _mapType[GRENADE] = 0;
        _mapType[TARGET] = 1;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    MotionManager::~MotionManager()
    {
    }
};