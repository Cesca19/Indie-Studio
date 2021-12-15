/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Motion
*/

#include "../../../include/Engine/Component/Motion.hpp"

namespace Engine {
Motion::Motion(double Vx, double Vy, double ax, double ay)
{
    _Vx = Vx;
    _Vy = Vy;
    _ax = ax;
    _ay = ay;
}

Motion::~Motion()
{
}

void Motion::setMotion(double Vx, double Vy, double ax, double ay)
{
    _Vx = Vx;
    _Vy = Vy;
    _ax = ax;
    _ay = ay;
}

double Motion::getVx() const
{
    return (_Vx);
}

double Motion::getVy() const
{
    return (_Vy);
}

double Motion::getax() const
{
    return (_ax);
}

double Motion::getay() const
{
    return (_ay);
}

}