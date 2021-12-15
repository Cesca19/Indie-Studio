/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetPosiTion
*/

#ifndef SYSTEMSETPOSITION_HPP_
#define SYSTEMSETPOSITION_HPP_
#include "ISystem.hpp"

namespace Engine {
    class SystemSetPosition : public ISystem
    {
    public:
        /**
         * @brief Construct a new System Set Position object
         * 
         * @param positionManager 
         */
        SystemSetPosition(std::shared_ptr<PositionManager> positionManager);
        /**
         * @brief Destroy the System Set Position object
         * 
         */
        ~SystemSetPosition();
        /**
         * @brief Set the Entity Position component
         * 
         * @param entity 
         * @param x 
         * @param y 
         * @param z 
         */
        void setEntityPosition(std::shared_ptr<Entity> entity, double x, double y, double z);
        /**
         * @brief update the system attribute each frame
         * 
         */
        void update();
    private:
        std::shared_ptr<PositionManager> _positionManager;
    };  
}

#endif /* !SYSTEMSETPOSITION_HPP_ */
