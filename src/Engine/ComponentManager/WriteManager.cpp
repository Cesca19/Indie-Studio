/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** WriteManager
*/

#include "WriteManager.hpp"

namespace Engine {
    std::shared_ptr<IComponent> WriteManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> WriteManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void WriteManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Write> component(new Write("", ""));
        _mapComponent[ptr] = component;
    }

    WriteManager::WriteManager()
    {
        _mapType[ALIEN] = 0;
        _mapType[PLAYER] = 0;
        _mapType[TARGET] = 0;
        _mapType[GRENADE] = 0;
        _mapType[WORD] = 1;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    WriteManager::~WriteManager()
    {
    }
};