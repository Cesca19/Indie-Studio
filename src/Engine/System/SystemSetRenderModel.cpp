/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetRenderModel
*/

#include "../../../include/Engine/System/SystemSetRenderModel.hpp"

namespace Engine {
    void SystemSetRenderModel::setEntityRenderModelAnimation(std::shared_ptr<Entity> entity, std::string fileName, int animsCount)
    {
        std::shared_ptr<RenderModel> renderComponent = std::dynamic_pointer_cast<RenderModel>(_renderModelManager->getComponent(entity));

        renderComponent->setAnimation(fileName, animsCount);
    }

    void SystemSetRenderModel::setEntityRenderModel(std::shared_ptr<Entity> entity, std::shared_ptr<Raylib::Texture> texture,
    std::string modelFile, Vector3 rotationAxis, Vector3 scale, float rotationAngle, Color color)
    {
        std::shared_ptr<RenderModel> renderComponent = std::dynamic_pointer_cast<RenderModel>(_renderModelManager->getComponent(entity));

        renderComponent->setRayModel(modelFile);
        renderComponent->setRotationAxis(rotationAxis);
        renderComponent->setScale(scale);
        renderComponent->setRotationAngle(rotationAngle);
        renderComponent->setColor(color);
        renderComponent->setTexture(texture);
    }

    void SystemSetRenderModel::update()
    {
    }

    SystemSetRenderModel::SystemSetRenderModel(std::shared_ptr<RenderModelManager> renderModelManager) : _renderModelManager(renderModelManager)
    {
    }

    SystemSetRenderModel::~SystemSetRenderModel()
    {
    }
};