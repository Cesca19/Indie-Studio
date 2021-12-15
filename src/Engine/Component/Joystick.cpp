/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Joystick
*/

#include "Joystick.hpp"

namespace Engine {
    int Joystick::getKeyLeft()
    {
        return _left;
    }

    int Joystick::getKeyRight()
    {
        return _right;
    }

    int Joystick::getKeyUp()
    {
        return _up;
    }

    int Joystick::getKeyDown()
    {
        return _down;
    }

    void Joystick::setKey(int left, int right, int up, int down)
    {
        _left = left;
        _right = right;
        _up = up;
        _down = down;
    }

    Joystick::Joystick()
    {
    }

    Joystick::~Joystick()
    {
    }
};
