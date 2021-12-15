/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ScriptManager
*/

#include "ScriptManager.hpp"

namespace Engine
{
    std::shared_ptr<IComponent> ScriptManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> ScriptManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void ScriptManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<Script> component(new Script);
        _mapComponent[ptr] = component;
    }

    ScriptManager::ScriptManager()
    {
        _mapType[ALIEN] = 0;
        _mapType[PLAYER] = 0;
        _mapType[TARGET] = 0;
        _mapType[GRENADE] = 0;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 0;
        _nbrEntity = 0;
    }

    ScriptManager::~ScriptManager()
    {
    }
};