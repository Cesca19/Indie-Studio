/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include "../AllEntities.hpp"
#include "../AllComponents.hpp"
#include "../AllComponentManagers.hpp"
#include <memory>
#include <unordered_map>

namespace Engine {
    class ISystem {
    public:
        virtual ~ISystem() = default;
        /**
         * @brief update the system attribute each fram
         * 
         */
        virtual void update() = 0;
    };
};

#endif /* !ISYSTEM_HPP_ */
