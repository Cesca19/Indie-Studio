/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Script
*/

#ifndef SCRIPT_HPP_
#define SCRIPT_HPP_

#include "IComponent.hpp"

namespace Engine
{
    /**
     * @class Engine::Script
     * Undefined
     */
    class Script : public IComponent
    {
    public:
        /**
         * A new script object
         */
        Script() = default;
        /**
         * Destructor
         */
        ~Script() = default;
    private:
    };
};

#endif /* !SCRIPT_HPP_ */
