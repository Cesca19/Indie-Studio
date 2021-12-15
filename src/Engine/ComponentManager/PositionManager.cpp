/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** PositionManager
*/

#include "../../../include/Engine/ComponentManager/PositionManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> PositionManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> PositionManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void PositionManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Position> component(new Position(0, 0, 0));
        _mapComponent[ptr] = component;
    }

    PositionManager::PositionManager()
    {
        _mapType[ALIEN] = 1;
        _mapType[PLAYER] = 1;
        _mapType[TARGET] = 1;
        _mapType[GRENADE] = 1;
        _mapType[WORD] = 1;
        _mapType[SPRITE] = 1;
        _nbrEntity = 0;
    }

    PositionManager::~PositionManager()
    {
    }
};
