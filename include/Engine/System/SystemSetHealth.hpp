/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetHealth
*/

#ifndef SYSTEMSETHEALTH_HPP_
#define SYSTEMSETHEALTH_HPP_

#include "ISystem.hpp"

namespace Engine {
class SystemSetHealth : public ISystem
{
    public:
        /**
         * @brief Construct a new System Set Health object
         * 
         * @param healthManager 
         */
        SystemSetHealth(std::shared_ptr<HealthManager> healthManager);
        /**
         * @brief Destroy the System Set Health object
         * 
         */
        ~SystemSetHealth();
        /**
         * @brief update the health component each frame
         * 
         */
        void update();

        /**
         * @brief Set the Entity Health object
         * 
         * @param entity 
         * @param current 
         * @param max 
         */
        void setEntityHealth(std::shared_ptr<Entity> entity, int current, int max=5);

        /**
         * @brief Set the Entity Position object
         * 
         * @param entity 
         * @param x 
         * @param y 
         */
        void setEntityPosition(std::shared_ptr<Entity> entity, int x, int y);
    private:
        std::shared_ptr<HealthManager> _healthManager;
    };
};

#endif /* !SYSTEMSETHEALTH_HPP_ */
