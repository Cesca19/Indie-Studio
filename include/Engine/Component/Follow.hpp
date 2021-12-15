/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Follow
*/

#ifndef FOLLOW_HPP_
#define FOLLOW_HPP_

#include "IComponent.hpp"

namespace Engine
{
    /**
     * @class Engine::Follow
     * Who to follow
     * This entity follow another one
     */
    class Follow : public IComponent
    {
    public:
        /**
         * Create a new follow component
         * @param component the component that the entity follows
         */
        Follow(IComponent *component);
        /**
         * @brief Set the Component object
         * 
         * @param component 
         */
        void setComponent(IComponent *component);
        /**
         * @brief Get the Component object
         * 
         * @return IComponent* 
         */
        IComponent *getComponent() const;
        /**
         * Destructor
         */
        ~Follow();
    private:
        IComponent *_component; /*< The component that the entity follows */
    };
};

#endif /* !FOLLOW_HPP_ */
