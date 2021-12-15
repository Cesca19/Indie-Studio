/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetHealth
*/

#include "../../../include/Engine/System/SystemSetHealth.hpp"

namespace Engine {
    void SystemSetHealth::setEntityPosition(std::shared_ptr<Entity> entity, int x, int y)
    {
        std::shared_ptr<Health> healthComponent = std::dynamic_pointer_cast<Health>(_healthManager->getComponent(entity));

        healthComponent->setPosition(x, y);
    }

    void SystemSetHealth::setEntityHealth(std::shared_ptr<Entity> entity, int current, int max)
    {
        std::shared_ptr<Health> healthComponent = std::dynamic_pointer_cast<Health>(_healthManager->getComponent(entity));

        healthComponent->setCurrentHealth(current);
        healthComponent->setMaxHealth(max);
    }

    void SystemSetHealth::update()
    {
    }

    SystemSetHealth::SystemSetHealth(std::shared_ptr<HealthManager> healthManager) : _healthManager(healthManager)
    {
    }

    SystemSetHealth::~SystemSetHealth()
    {
    }
};