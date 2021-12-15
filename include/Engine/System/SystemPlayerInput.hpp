/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemPlayerInput
*/

#ifndef SYSTEMPLAYERINPUT_HPP_
#define SYSTEMPLAYERINPUT_HPP_

#include "ISystem.hpp"

namespace Engine {
class SystemPlayerInput : public ISystem
{
    public:
        SystemPlayerInput(std::shared_ptr<PositionManager> positionManager, std::shared_ptr<JoystickManager> joystickManager, std::shared_ptr<RenderModelManager> renderModelManager, std::shared_ptr<CollisionManager> collisionManager, std::vector<std::shared_ptr<Entity>> *entities);
        ~SystemPlayerInput();
        void moveUp(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent);
        void moveDown(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent);
        void moveLeft(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent);
        void moveRight(double &x, double z, std::shared_ptr<Joystick> joystickComponent, std::shared_ptr<RenderModel> renderModelComponent,  std::shared_ptr<Collision> collisionComponent);
        void update();
    private:
        void updatePlayerPosition(std::shared_ptr<Entity> entity);
        std::shared_ptr<JoystickManager> _joystickManager;
        std::shared_ptr<PositionManager> _positionManager;
        std::shared_ptr<RenderModelManager> _renderModelManager;
        std::shared_ptr<CollisionManager> _collisionManager;
        std::vector<std::shared_ptr<Entity>> *_entities;
    };
};

#endif /* !SYSTEMPLAYERINPUT_HPP_ */
