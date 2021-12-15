/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** WriteManager
*/

#ifndef WRITEMANAGER_HPP_
#define WRITEMANAGER_HPP_

#include "IComponentManager.hpp"

namespace Engine {
    class WriteManager  : public IComponentManager
    {
        public:
            /**
             * @brief Construct a new Write Manager object
             * 
             */
            WriteManager();
            /**
             * @brief Destroy the Write Manager object
             * 
             */
            ~WriteManager();
            /**
             * Add a new entity to the SpriteManager
             * @param ptr This is the new entity to add to the Manager
             */
            void addEntity(std::shared_ptr<Entity> ptr);
            /**
             * Get all the entity that the SpriteManager contains
             * @return std::vector<std::shared_ptr<Entity>> A vector which contains the Id
             * of all the entities that the manger contains
             */
            std::vector<std::shared_ptr<Entity>> getAllEntity();

            /**
             * @brief Get the Component object
             * 
             * @param entity 
             * @return std::shared_ptr<Write> 
             */
            std::shared_ptr<IComponent> getComponent(std::shared_ptr<Entity> entity);
        private:
            std::unordered_map<entityType, bool> _mapType; /*< A map that define if the manager hold a type of Entity*/
            std::vector<std::shared_ptr<Entity>> _entityArray; /*< The id of all entities that the manger contains */
            std::unordered_map<std::shared_ptr<Entity>, std::shared_ptr<Write>> _mapComponent; /*< The component associated to
            * to each entity
            */
            int _nbrEntity; /*< The number of entities */
    };
};

#endif /* !WRITEMANAGER_HPP_ */