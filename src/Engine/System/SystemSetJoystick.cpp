/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetJoystick
*/

#include "../../../include/Engine/System/SystemSetJoystick.hpp"

namespace Engine {
    void SystemSetJoystick::setEntityJoystick(std::shared_ptr<Entity> entity, int left, int right, int up, int down)
    {
        std::shared_ptr<Joystick> joystickComponent = std::dynamic_pointer_cast<Joystick>(_joystickManager->getComponent(entity));

        joystickComponent->setKey(left, right, up, down);
    }

    void SystemSetJoystick::update()
    {
    }

    SystemSetJoystick::SystemSetJoystick(std::shared_ptr<JoystickManager> joystickManager) : _joystickManager(joystickManager)
    {
    }

    SystemSetJoystick::~SystemSetJoystick()
    {
    }
};