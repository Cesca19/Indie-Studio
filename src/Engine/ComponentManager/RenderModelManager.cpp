/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RenderModelManager
*/

#include "RenderModelManager.hpp"

namespace Engine {
    std::shared_ptr<IComponent> RenderModelManager::getComponent(std::shared_ptr<Entity> entity)
    {
        if (!_mapComponent[entity])
            return NULL;
        return _mapComponent[entity];
    }

    std::vector<std::shared_ptr<Entity>> RenderModelManager::getAllEntity(void)
    {
        return (_entityArray);
    }

    void RenderModelManager::addEntity(std::shared_ptr<Entity> ptr)
    {
        if (!_mapType[ptr->getType()])
            return;
        _nbrEntity += 1;
        _entityArray.push_back(ptr);
        std::shared_ptr<RenderModel> component(new RenderModel());
        _mapComponent[ptr] = component;
    }

    RenderModelManager::RenderModelManager()
    {
        _mapType[ALIEN] = 0;
        _mapType[PLAYER] = 1;
        _mapType[TARGET] = 0;
        _mapType[GRENADE] = 1;
        _mapType[WORD] = 0;
        _mapType[SPRITE] = 1;
        _nbrEntity = 0;
    }

    RenderModelManager::~RenderModelManager()
    {
    }
};