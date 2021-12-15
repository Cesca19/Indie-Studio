/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <memory>

namespace Engine {
    class IComponent {
        public:
            virtual ~IComponent() = default;
    };

    /**
     * @class Engine::IComponent
     * A Component is a singular behavior ascribed to an entity
     * An entity can have many components
     */
};

#endif /* !ICOMPONENT_HPP_ */
