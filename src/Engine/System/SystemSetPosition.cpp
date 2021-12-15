/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetPosiion
*/

#include "SystemSetPosition.hpp"

namespace Engine {
    void SystemSetPosition::setEntityPosition(std::shared_ptr<Entity> entity, double x, double y, double z)
    {
        std::shared_ptr<Position> positionComponent = std::dynamic_pointer_cast<Position>(_positionManager->getComponent(entity));
        positionComponent->setPosition(x, y, z);
    }

    void SystemSetPosition::update()
    {
    }

    SystemSetPosition::SystemSetPosition(std::shared_ptr<PositionManager> positionManager) : _positionManager(positionManager)
    {
    }

    SystemSetPosition::~SystemSetPosition()
    {
    }
};