/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemPlayerInput
*/

#include "SystemPlayerInput.hpp"

namespace Engine {

    void SystemPlayerInput::moveRight(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent)
    {
        static double timer = 0;
        static int doesMove = 0;

        if (Raylib::isKeyDown(joystickComponent->getKeyRight())) {
            doesMove = 1;
            timer = Raylib::getTime();
            renderModelComponent->setRotationAngle(190);
        } else {
            doesMove = 0;
        }
        if (doesMove && Raylib::getTime() - timer < 0.15 && collisionComponent->canMove(x + 1, z) ) {// && collisionComponent->canMove((int)x + 1, (int)z) && collisionComponent->canMove((int)x, (int)z) && collisionComponent->canMove((int)x, (int)z)  ) {
            x += 0.05;
        }
        else {
            doesMove = 0;
        }
    }

    void SystemPlayerInput::moveLeft(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent)
    {
        static double timer = 0;
        static int doesMove = 0;

        if (Raylib::isKeyDown(joystickComponent->getKeyLeft())) {
            doesMove = 1;
            timer = Raylib::getTime();
            renderModelComponent->setRotationAngle(360);
        } else {
            doesMove = 0;
        }
        if (doesMove && Raylib::getTime() - timer < 0.15 && collisionComponent->canMove(x - 0.3, z) ) {//  && collisionComponent->canMove((int)x - 1, (int)z) ) {
            x -= 0.05;
        }
        else {
            doesMove = 0;
        }
    }

    void SystemPlayerInput::moveUp(double &z, double x, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent)
    {
        static double timer = 0;
        static int doesMove = 0;

        if (Raylib::isKeyDown(joystickComponent->getKeyUp())) {
            doesMove = 1;
            timer = Raylib::getTime();
            renderModelComponent->setRotationAngle(260);
        } else {
            doesMove = 0;
        }
        if (doesMove && Raylib::getTime() - timer < 0.15 && collisionComponent->canMove(x , z - 0.6) ) {//  && collisionComponent->canMove((int)x, (int)z - 1) ) {
            z -= 0.05;
        }
        else {
            doesMove = 0;
        }
    }

    void SystemPlayerInput::moveDown(double &z, double x, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent)
    {
        static double timer = 0;
        static int doesMove = 0;
        int zz = (int)z;

        if (Raylib::isKeyDown(joystickComponent->getKeyDown())) {
            doesMove = 1;
            timer = Raylib::getTime();
            renderModelComponent->setRotationAngle(90);
        } else {
            doesMove = 0;
        }
        if (doesMove && Raylib::getTime() - timer < 0.15 && collisionComponent->canMove(x , z + 0.4) ) {// && collisionComponent->canMove((int)x, (int)zz + 1) && collisionComponent->canMove((int)x, (int)zz + 1) && collisionComponent->canMove((int)x, (int)zz + 1) ) {
            z += 0.05;
        }
        else {
            doesMove = 0;
        }
    }

    void SystemPlayerInput::updatePlayerPosition(std::shared_ptr<Entity> entity)
    {
        std::shared_ptr<Joystick> joystickComponent = std::dynamic_pointer_cast<Joystick>(_joystickManager->getComponent(entity));
        std::shared_ptr<Position> positionComponent = std::dynamic_pointer_cast<Position>(_positionManager->getComponent(entity));
        std::shared_ptr<RenderModel> renderModelComponent = std::dynamic_pointer_cast<RenderModel>(_renderModelManager->getComponent(entity));
        std::shared_ptr<Collision> collisionComponent = std::dynamic_pointer_cast<Collision>(_collisionManager->getComponent(entity));
        double x = positionComponent->getx(), y = positionComponent->gety(), z = positionComponent->getz();

        collisionComponent->canMove(x, z);
        moveUp(z, x, joystickComponent, renderModelComponent, collisionComponent);
        moveRight(x, z, joystickComponent, renderModelComponent, collisionComponent);
        moveLeft(x, z,joystickComponent, renderModelComponent, collisionComponent);
        moveDown(z, x,joystickComponent, renderModelComponent, collisionComponent);
        positionComponent->setPosition(x, y, z);
    }

    void SystemPlayerInput::update()
    {
        for (int i = 0; i < (*_entities).size(); i++) {
            if ((*_entities)[i]->getType() == PLAYER)
                updatePlayerPosition((*_entities)[i]);
        }
    }

    SystemPlayerInput::SystemPlayerInput(std::shared_ptr<PositionManager> positionManager, std::shared_ptr<JoystickManager> joystickManager, std::shared_ptr<RenderModelManager> renderModelManager, std::shared_ptr<CollisionManager> collisionManager, std::vector<std::shared_ptr<Entity>> *entities) : _joystickManager(joystickManager), _positionManager(positionManager), _renderModelManager(renderModelManager), _entities(entities), _collisionManager(collisionManager)
    {
    }

    SystemPlayerInput::~SystemPlayerInput()
    {
    }
};