/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Grenade
*/

#ifndef GRENADE_HPP_
#define GRENADE_HPP_

#include "Entity.hpp"

namespace Engine
{
    class Grenade : public Entity{
    public:
        /**
         * Construct a new Grenade
         * @param name This is the Alien Name
         */
        Grenade(std::string name = "Alien");
        /**
         * Destructor
         */
        ~Grenade();
    };
};

#endif /* !Grenade_HPP_ */
