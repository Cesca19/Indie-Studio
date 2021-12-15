/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** IComponentManager
*/

#ifndef ICOMPONENTMANAGER_HPP_
#define ICOMPONENTMANAGER_HPP_

#include "../AllComponents.hpp"
#include "../AllEntities.hpp"
#include <vector>
#include <unordered_map>
#include <memory>

namespace Engine {
    class IComponentManager {
    public:
        virtual ~IComponentManager() = default;
        virtual void addEntity(std::shared_ptr<Entity> ptr) = 0;
        virtual std::vector<std::shared_ptr<Entity>> getAllEntity() = 0;
        virtual std::shared_ptr<IComponent> getComponent(std::shared_ptr<Entity> entity) = 0;
    };
};

#endif /* !ICOMPONENTMANAGER_HPP_ */
