/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "../../Raylib/raylib.hpp"
//#include "../Scene/Scene.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace Engine
{
    class IButton
    {
    public:
        /**
         * @brief Destroy the IButton object
         * 
         */
        virtual ~IButton() = default;
        /**
         * @brief Set the position of the text
         * 
         * @param position 
         */
        virtual void setPosition(Vector2 position) = 0;
        /**
         * @brief Get the position of the text
         * 
         * @return Vector2 
         */
        virtual Vector2 getPosition() const = 0;
        /**
         * @brief check the button state
         * 
         * @return int 
         */
        virtual int checkState() = 0;
        /**
         * @brief update the button state
         * 
         */
        virtual void updateState() = 0;
        /**
         * @brief display the button on the screen
         * 
         */
        virtual void draw() = 0;
        /**
         * @brief Set the Sound of the button
         * 
         * @param ishover 
         * @param isclisk 
         */
        virtual void setSound(std::string ishover, std::string isclisk) = 0;
        virtual std::string getName() = 0;
        //virtual void setLinkFunc(void (Raylib::Window:: *function) ()) = 0;
        virtual void setLinkScene(void *link) = 0;

        /**
         * @brief Set the Map Scene object
         * 
         * @param mapScene casted in void *
         */
        virtual void setMapScene(void *mapScene) = 0;
    };
};

#endif /* !IBUTTON_HPP_ */
