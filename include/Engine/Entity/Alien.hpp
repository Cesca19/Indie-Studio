/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Alien
*/

#ifndef ALIEN_HPP_
#define ALIEN_HPP_

#include "Entity.hpp"

namespace Engine
{
    class Alien : public Entity{
    public:
        /**
         * Construct a new Alien Object
         * @param name
         */
        Alien(std::string name = "Alien");
        /**
         * Alien Destructor
         */
        ~Alien();
    };
};

#endif /* !ALIEN_HPP_ */
