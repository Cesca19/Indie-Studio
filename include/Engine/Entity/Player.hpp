/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Entity.hpp"

namespace Engine
{
    class Player : public Entity{
        public:
        /**
         * Construct a new player
         * @param name
         */
        Player(std::string name = "");
        
        /**
         * Destructor
         */
        ~Player();
    };
};

#endif /* !PLAYER_HPP_ */
