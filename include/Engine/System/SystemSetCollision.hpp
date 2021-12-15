/*
** EPITECH PROJECT, 2021
** INDIE
** File description:
** SystemSetCollision
*/

#ifndef SYSTEMSETCOLLISION_HPP_
#define SYSTEMSETCOLLISION_HPP_

#include "ISystem.hpp"

namespace Engine {

    class SystemSetCollision : public ISystem{
    public:

    void update(void);

    /**
     * @brief Set the Map Info object
     * 
     * @param entity the entity
     * @param map the address of the selected map please ;)
     * @param goodPlaces Places where we can move
     */
    void setMapInfo(std::shared_ptr<Entity> entity, std::vector<std::string> **map, std::string goodPlaces);

    /**
     * @brief Construct a new System Set Collision object
     * 
     * @param collisionManager 
     */
        SystemSetCollision(std::shared_ptr<CollisionManager> collisionManager);

    /**
     * @brief Destroy the System Set Collision object
     * 
     */
        ~SystemSetCollision();

    protected:
    private:
        std::shared_ptr<CollisionManager> _collisionManager;
    };
};

#endif /* !SYSTEMSETCOLLISION_HPP_ */
