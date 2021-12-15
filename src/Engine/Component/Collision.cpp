/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Collision
*/

#include "Collision.hpp"

namespace Engine  {

    bool Collision::canMove(double xReal, double yReal)
    {
        static double lastx = 0;
        static double lasty = 0;
        int xPlus = ((lastx - xReal > 0) ? -1 : 1);
        int yPlus = ((lasty - yReal  < 0) ? 1 : -1);
        xPlus = ((lastx == xReal) ?  0 : xPlus);
        yPlus = ((lasty == yReal) ? 0 : yPlus);
        int x = (int)xReal;
        int y = (int)yReal;
        lastx = xReal;
        lasty = yReal;

        if (!_map)
            return 0;
        xReal += 16;
        yReal += 9;
        x += 16;
        y += 9;
        if (xReal - x > 0.3)
            x += 1;
        if (yReal - y > 0.3)
            y += 1;
        if (y - 1>= (**_map).size() || y - 1< 0)
            return (0);
        if (x  - 1>= (**_map)[0].size() || x - 1 < 0)
            return (0);
        char c = (**_map)[y - 1][x - 1];

        for (int i = 0; _goodPlaces[i]; i++) {
            if (_goodPlaces[i] == c)
                return (1);
        }
        return (0);
    }

    void Collision::setMap(std::vector<std::string> **map)
    {
        _map = map;
    }

    void Collision::setGoodPlaces(std::string goodPlaces)
    {
        _goodPlaces = goodPlaces;
    }
};

Engine::Collision::Collision(int width, int height)
{
    _width = width;
    _height = height;
    _map = NULL;
}

void Engine::Collision::setSize(int width, int height)
{
    _width = width;
    _height = height;
}

int Engine::Collision::getHeight() const
{
    return (_height);
}

int Engine::Collision::getWidth() const
{
    return (_width);
}

Engine::Collision::~Collision()
{
}
