/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetJoystick
*/

#ifndef SYSTEMSETJOYSTICK_HPP_
#define SYSTEMSETJOYSTICK_HPP_

#include "ISystem.hpp"

namespace Engine {
    class SystemSetJoystick : public ISystem
    {
    public:
        /**
         * @brief Construct a new System Set Joystick object
         * 
         * @param joystickManager 
         */
        SystemSetJoystick(std::shared_ptr<JoystickManager> joystickManager);
        /**
         * @brief Destroy the System Set Joystick object
         * 
         */
        ~SystemSetJoystick();
        /**
         * @brief update all joystick component each frame
         * 
         */
        void update();
        /**
         * @brief Set the Entity Joystick object
         * 
         * @param entity 
         * @param left 
         * @param right 
         * @param up 
         * @param down 
         */
        void setEntityJoystick(std::shared_ptr<Entity> entity, int left, int right, int up, int down);
    private:
        std::shared_ptr<JoystickManager> _joystickManager;
    };
};

#endif /* !SYSTEMSETJOYSTICK_HPP_ */
