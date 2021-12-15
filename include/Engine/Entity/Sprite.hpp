/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "Entity.hpp"

namespace Engine {
    class Sprite : public Entity
    {
    public:
        /**
         * @brief Construct a new Sprite object
         * 
         * @param name 
         */
        Sprite(std::string name = "sprite");
        
        /**
         * @brief Destroy the Sprite object
         * 
         */
        ~Sprite();
    private:
    };
};
#endif /* !SPRITE_HPP_ */
