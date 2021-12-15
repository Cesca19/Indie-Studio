/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Joystick
*/

#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_

#include "IComponent.hpp"
#include "../../Raylib/raylib.hpp"

namespace Engine {
    /**
     * @class Engine::Joystick
     * Key configuration
     * This entity can move based on arrow keys
     */
    class Joystick : public IComponent{
    public:
        /**
         * Create a new joystick Component
        */
        Joystick();
        
        /*
         * Destructor
         */
        ~Joystick();

        /**
         * @brief Set the Key object
         * 
         * @param left 
         * @param right 
         * @param up 
         * @param down 
         */
        void setKey(int left, int right, int up, int down);

        /**
         * @brief Get the Key Left object
         * 
         * @return int 
         */
        int getKeyLeft();

        /**
         * @brief Get the Key Right object
         * 
         * @return int 
         */
        int getKeyRight();

        /**
         * @brief Get the Key Up object
         * 
         * @return int 
         */
        int getKeyUp();

        /**
         * @brief Get the Key Down object
         * 
         * @return int 
         */
        int getKeyDown();
        
    private:
        int _left;
        int _right;
        int _up;
        int _down;
    };
};

#endif /* !JOYSTICK_HPP_ */
