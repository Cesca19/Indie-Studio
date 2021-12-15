/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "IComponent.hpp"

namespace Engine
{
    /**
     * @class Engine::Position
     * This entity has a position in the world
     */
    class Position : public IComponent
    {
    public:
        /**
         * Create a new position Component
         * @param x
         * @param y
         * @param z
         */
        Position(double x, double y, double z);
        ~Position();

        /**
         * @brief Set the position of the object
         * 
         * @param x 
         * @param y 
         * @param z 
         * @return ** void 
         */
        void setPosition(double x, double y, double z);

        /**
         * @brief Get x coordinate of the object
         * 
         * @return ** double 
         */
        double getx() const;

        /**
         * @brief Get y coordinate of the object
         * 
         * @return ** double 
         */
        double gety() const;

        /**
         * @brief Get z coordinate of the object
         * 
         * @return ** double 
         */
        double getz() const;
    protected:
    private:
        double _x; /*< */
        double _y; /*< */
        double _z; /*< */
    };
};

#endif /* !POSITION_HPP_ */
