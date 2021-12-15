/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemRender
*/

#include "../../../include/Engine/System/SystemRender.hpp"

namespace Engine  {
    void SystemRender::update()
    {
        for (int i = 0; i < (*_entities).size(); i++) {
            if ((*_entities)[i]->getType() == WORD)
                drawWord((*_entities)[i]);
        }
    }

    void SystemRender::update(Camera *camera)
    {
        for (int i = 0; i < (*_entities).size(); i++) {
            switch ((*_entities)[i]->getType())
            {
            case WORD:
                drawWord((*_entities)[i]);
                break;
            case SPRITE:
                drawSprite((*_entities)[i], camera);
                break;
            case PLAYER:
                drawSprite((*_entities)[i], camera);
                drawHealth((*_entities)[i]);
                break;
            case GRENADE:
                drawBomb((*_entities)[i], camera);
                break;
            default:
                break;
            }   
        }
    }

    void SystemRender::drawHealth(std::shared_ptr<Entity> entity)
    {
        std::shared_ptr<Health> healthComponent = std::dynamic_pointer_cast<Health>((*_mapComponentManger)["HealthManager"]->getComponent(entity));

        healthComponent->display();
    }

    void SystemRender::drawWord(std::shared_ptr<Entity> entity)
    {   
        if (!entity->canDraw())
            return ;
        std::shared_ptr<Write> writeComponent = std::dynamic_pointer_cast<Write>((*_mapComponentManger)["WriteManager"]->getComponent(entity));
        std::shared_ptr<Position> positionComponent = std::dynamic_pointer_cast<Position>((*_mapComponentManger)["PositionManager"]->getComponent(entity));
        
        if (!writeComponent || !positionComponent)
            return;
        std::shared_ptr<Raylib::Text> text = writeComponent->getText();
        text->setPosition(Vector2{(float)positionComponent->getx(), (float)positionComponent->gety()});
        text->setColor(writeComponent->getColor());
        text->draw();
    }

    void SystemRender::drawBomb(std::shared_ptr<Entity> entity, Camera *camera)
    {
        if (!entity->canDraw())
            return ;
        std::shared_ptr<RenderModel> renderModelComponent = std::dynamic_pointer_cast<RenderModel>((*_mapComponentManger)["RenderModelManager"]->getComponent(entity));
        std::shared_ptr<Position> positionComponent = std::dynamic_pointer_cast<Position>((*_mapComponentManger)["PositionManager"]->getComponent(entity));
        
        if (!renderModelComponent || !positionComponent)
            return;
        std::shared_ptr<Raylib::RayModel> model = renderModelComponent->getModel();
 
        Raylib::beginMode3D(*camera);
        model->drawEx(Vector3{(float)positionComponent->getx(), (float)positionComponent->gety(), 
        (float)positionComponent->getz()}, renderModelComponent->getRotationAxis(), 
        renderModelComponent->getRotationAngle(), renderModelComponent->getScale(),
        renderModelComponent->getColor());
        Raylib::endMode3D();
    }

    void SystemRender::drawSprite(std::shared_ptr<Entity> entity, Camera *camera)
    {
        if (!entity->canDraw())
            return ;
        static int animFrameCounter = 0;
        static int framesCounter = 0;
        std::shared_ptr<RenderModel> renderModelComponent = std::dynamic_pointer_cast<RenderModel>((*_mapComponentManger)["RenderModelManager"]->getComponent(entity));
        std::shared_ptr<Position> positionComponent = std::dynamic_pointer_cast<Position>((*_mapComponentManger)["PositionManager"]->getComponent(entity));
        
        if (!renderModelComponent || !positionComponent)
            return;
        std::shared_ptr<Raylib::RayModel> model = renderModelComponent->getModel();
        
        framesCounter++;
        if (framesCounter >= (1)) {
            framesCounter = 0;
            model->updateAnimation(animFrameCounter);
            if (animFrameCounter >= model->getAnimsFrameCount()) animFrameCounter = 0;
            animFrameCounter++;
        }

        Raylib::beginMode3D(*camera);
        model->drawEx(Vector3{(float)positionComponent->getx(), (float)positionComponent->gety(), 
        (float)positionComponent->getz()}, renderModelComponent->getRotationAxis(), 
        renderModelComponent->getRotationAngle(), renderModelComponent->getScale(),
        renderModelComponent->getColor());
        Raylib::endMode3D();
    }

    SystemRender::SystemRender(std::unordered_map<std::string, std::shared_ptr<IComponentManager>> *mapComponentManger, std::vector<std::shared_ptr<Entity>> *entities) : _mapComponentManger(mapComponentManger), _entities(entities)
    {
    }

    SystemRender::~SystemRender()
    {
    }
}