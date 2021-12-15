/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "IComponent.hpp"
#include <vector>

namespace Engine
{
    /**
     * @class Engine::Collision
     *  Define the size of the entity's collision box
     */
    class Collision : public IComponent
    {
    public:
        /**
         * Create a new Collision Component
         * @param width Width of the collision box
         * @param height Height of the collision box
         */
        Collision(int width, int height);
        /**
         * Destructor
         */
        ~Collision();
        /**
         * @brief Set the width and the height
         * 
         * @param width 
         * @param height 
         */
        void setSize(int width, int height);
        /**
         * @brief Get the Width object
         * 
         * @return int 
         */
        int getWidth() const;
        /**
         * @brief Get the Height object
         * 
         * @return int 
         */
        int getHeight() const;

        /**
         * @brief Set the Map object
         * 
         * @param map 
         */
        
        void setMap(std::vector<std::string> **map);
        /**
         * @brief Set the Good Places object
         * 
         * @param goodPlaces 
         */
        void setGoodPlaces(std::string goodPlaces);

        /**
         * @brief return 1 if the entity can Move to this position
         * 
         * @param x x
         * @param y y
         * @return true 
         * @return false 
         */
        bool canMove(double x, double y);

    protected:
        int _width; /*<  Width of the collision box */
        int _height; /*< Height of the collision box */
        std::vector<std::string> **_map; // the map
        std::string _goodPlaces;

    };
};

#endif /* !COLLISION_HPP_ */
