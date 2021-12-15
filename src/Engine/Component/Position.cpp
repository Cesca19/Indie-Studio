/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Position
*/

#include "Position.hpp"

namespace Engine {

Position::Position(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Position::~Position()
{
}

void Position::setPosition(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Position::getx() const
{
    return (_x);
}

double Position::gety() const
{
    return (_y);
}

double Position::getz() const
{
    return (_z);
}

}