/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_

#include "IComponent.hpp"
#include <memory>
#include <vector>
#include "../../Raylib/raylib.hpp"

namespace Engine
{
    /**
     * @class Engine::Health
     * This entity can take damage
     */
    class Health : public IComponent
    {
    public:
        /**
         * Create a new health component
         * @param max The max health of the entity
         */
        Health(int max=5);
        /**
         * @brief Set the Current Health object
         * 
         * @param health 
         */
        void setCurrentHealth(int health);
        /**
         * @brief Set the Max Health object
         * 
         * @param health 
         */
        void setMaxHealth(int health);
        /**
         * @brief Get the Current Health object
         * 
         * @return int 
         */
        int getCurrentHealth() const;

        /**
         * @brief Set the Position object
         * 
         * @param x 
         * @param y 
         */
        void setPosition(int x, int y);

        /**
         * @brief Get the Max Health object
         * 
         * @return int 
         */
        int getMaxHealth() const;
        /**
         * Destructor
         */
        ~Health();

        /**
         * @brief display the entity health on the screen
         * 
         */
        void display();

    protected:
    private:
        int _max; /*< */
        int _current; /*< */
        std::vector<std::shared_ptr<Raylib::Texture>> _health;
        int _x;
        int _y;
        Raylib::Text _name;
    };
};

#endif /* !HEALTH_HPP_ */
