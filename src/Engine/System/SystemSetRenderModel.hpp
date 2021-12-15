/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetRenderModel
*/

#ifndef SYSTEMSETRENDERMODEL_HPP_
#define SYSTEMSETRENDERMODEL_HPP_

#include "ISystem.hpp"

namespace Engine {
    class SystemSetRenderModel : public ISystem
    {
    public:
        /**
         * @brief Construct a new System Set Render Model object
         * 
         * @param renderModelManager 
         */
        SystemSetRenderModel(std::shared_ptr<RenderModelManager> renderModelManager);
        
        /**
         * @brief Destroy the System Set Render Model object
         * 
         */
        ~SystemSetRenderModel();
        
        /**
         * @brief update the system attribute each frame
         * 
         */
        void update();

        /**
         * @brief Set the Entity Render Model object 
         * 
         * @param entity 
         * @param modelFile 
         * @param rotationAxis 
         * @param scale
         * @param rotationAngle 
         * @param color 
         */
        void setEntityRenderModel(std::shared_ptr<Entity> entity, std::shared_ptr<Raylib::Texture> texture,
        std::string modelFile, Vector3 rotationAxis, Vector3 scale, float rotationAngle, Color color);
        
        /**
         * @brief Set the Entity Render Model Animation object
         * 
         * @param fileName 
         * @param animsCount 
         */
        void setEntityRenderModelAnimation(std::shared_ptr<Entity> entity, std::string fileName, int animsCount);
    private:
        std::shared_ptr<RenderModelManager> _renderModelManager;
    };
};

#endif /* !SYSTEMSETRENDERMODEL_HPP_ */
