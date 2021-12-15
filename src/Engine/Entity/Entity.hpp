/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>

namespace Engine
{
    static unsigned int id = 0;

    typedef enum {
        PLAYER,
        GRENADE,
        ALIEN,
        TARGET,
        WORD,
        SPRITE
    } entityType;

    /**
    * @enum Engine::entityType This enum handle the different types of Entity
    */

    class Entity {
    public:
        /**
         * Construct a new Entity
         * @param type
         * @param name
         */
        Entity(entityType type, std::string name = "");
        /**
         * Destructor
         */
        ~Entity();
        /**
         * This method give the entity Id
         * @return type: unsigned int which is the Id of the entity
         */
        unsigned int getId() const;
        /**
         * This method give the entity type
         * @return type: Engine::entityType which is the type of the Entity
         */
        entityType getType() const;

        std::string getName();

        void draw();

        bool canDraw();

        void unDraw();
    protected:
        bool _draw;
        unsigned int _id; /**< Entity Id*/
        std::string _name; /**< Entity Name*/
        entityType _type; /**< Entity Type*/
    };

    /**
     * @class Engine::Entity
     * An entity is any object contained in a game scene
     */
}

#endif /* !ENTITY_HPP_ */
