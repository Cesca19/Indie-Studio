/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Target
*/

#ifndef TARGET_HPP_
#define TARGET_HPP_

#include "Entity.hpp"

namespace Engine
{
    class Target : public Entity{
    public:
        /**
         * Construct a new Target
         * @param name
         */
        Target(std::string name = "");
        /**
         * Destruvtor
         */
        ~Target();
    };
};

#endif /* !Target_HPP_ */
