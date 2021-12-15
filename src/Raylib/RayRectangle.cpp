/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Rectangle
*/

#include "RayRectangle.hpp"

namespace Raylib {
    void RayRectangle::draw(float roundness, int segments, Color color)
    {
        DrawRectangleRounded(_rect, roundness, segments, color);
    }

    void RayRectangle::setPosition(Vector2 pos)
    {
        _pos = pos;
    }

    void RayRectangle::setPosition(float x, float y)
    {
        _pos.x = x;
        _pos.y = y;
        _rect.x = x;
        _rect.y = y;
    }

    RayRectangle::RayRectangle(float width, float height)
    {
        _width = width;
        _height = height;
        _rect.height = height;
        _rect.width = width;
    }

    RayRectangle::~RayRectangle()
    {
    }

    void RayRectangle::updRayRectangle(float x, float y, float width, float height)
    {
        _rect = {x, y, width, height};
    }

    Rectangle RayRectangle::getRect()
    {
        return (_rect);
    }

    void RayRectangle::draw(Color color)
    {
        DrawRectangleRec(_rect, color);
    }

    bool RayRectangle::checkCollisionRayRecs(RayRectangle rec)
    {
        return (CheckCollisionRecs(_rect, rec.getRect()));
    }

    bool RayRectangle::pointOnRayRectangle(Vector2 point)
    {
        return (CheckCollisionPointRec(point, _rect));
    }
};
