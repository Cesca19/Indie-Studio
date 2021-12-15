/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemRender
*/

#ifndef SYSTEMRENDER_HPP_
#define SYSTEMRENDER_HPP_

#include "ISystem.hpp"

namespace Engine {
    class SystemRender : public ISystem
    {
    public:
        /**
         * @brief Construct a new System Render object
         * 
         * @param mapComponentManger 
         * @param entities 
         */
        SystemRender(std::unordered_map<std::string, std::shared_ptr<IComponentManager>> *mapComponentManger, std::vector<std::shared_ptr<Entity>> *entities);
        
        /**
         * @brief Destroy the System Render object
         * 
         */
        ~SystemRender();
        
        /**
         * @brief update the system attribute each frame
         * 
         */
        void update();

        /**
         * @brief update the system attribute each frame
         * 
         * @param camera 
         */
        void update(Camera *camera);
    private:
        /**
         * @brief draw all word entities
         * 
         * @param entity 
         */
        void drawWord(std::shared_ptr<Entity> entity);

        /**
         * @brief draw all Sprite entities
         * 
         * @param entity 
         */
        void drawSprite(std::shared_ptr<Entity> entity, Camera *camera);

        /**
         * @brief draw all Bomb entities
         * 
         * @param entity 
         * @param camera 
         */
        void drawBomb(std::shared_ptr<Entity> entity, Camera *camera);

        /**
         * @brief draw all player health entities
         * 
         * @param entity 
         */
        void drawHealth(std::shared_ptr<Entity> entity);
    private:
        std::unordered_map<std::string, std::shared_ptr<IComponentManager>> *_mapComponentManger;
        std::vector<std::shared_ptr<Entity>> *_entities;
    };
};

#endif /* !SYSTEMRENDER_HPP_ */
