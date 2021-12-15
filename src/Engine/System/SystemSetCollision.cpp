/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetCollision
*/

#include "SystemSetCollision.hpp"

namespace Engine {

void SystemSetCollision::update(void)
{
}

void SystemSetCollision::setMapInfo(std::shared_ptr<Entity> entity, std::vector<std::string> **map, std::string goodPlaces)
{
    std::shared_ptr<Collision> CollisionComponent = std::dynamic_pointer_cast<Collision>(_collisionManager->getComponent(entity));

    CollisionComponent->setMap(map);
    CollisionComponent->setGoodPlaces(goodPlaces);
}

SystemSetCollision::SystemSetCollision(std::shared_ptr<CollisionManager> collisionManager)
{
    _collisionManager = collisionManager;
}

SystemSetCollision::~SystemSetCollision()
{
}

};
