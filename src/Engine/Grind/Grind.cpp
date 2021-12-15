/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Grind
*/

#include "Grind.hpp"

namespace Engine {

    int Grind::checkRectState(Raylib::RayRectangle *rect)
    {
        Vector2 position = Raylib::getMousePosition();

        if (rect->pointOnRayRectangle(position)
        && (Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT) ||  Raylib::isMouseButtonPressed(MOUSE_BUTTON_RIGHT)))
            return (2);
        if (rect->pointOnRayRectangle(position)
        && (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonDown(MOUSE_BUTTON_RIGHT)))
            return (2);
        if (!rect->pointOnRayRectangle(position))
            return (0);
        if(rect->pointOnRayRectangle(position))
            return (1);
        
        return (0);
    }

    void Grind::drawRect(char c)
    {
        int status = 0;
        int pos = 0;
        Rectangle rect;

        //for (int i = 0; i < _rectArr.size(); i++) {
        for (int i = 0; i < _map.size(); i++) {
            for (int j = 0; _map[i][j]; j++) {
                pos = i * _y + j;
                status = checkRectState(&_rectArr[i][j]); 
                if (status) {
                    rect = _rectArr[i][j].getRect();
                    DrawRectangleLines(rect.x, rect.y, 30, 30, GREEN);
                    if (status == 2)
                        _map[i][j] = c;
                }
            }
        }
    }

    void Grind::initRect(void)
    {
        Rectangle rect = _typeWall[_map[0][0]]->getRectangle();
        int x = 0;
        int y = 0;

        for (int i = 0; i < _map.size(); i++) {
            std::vector<Raylib::RayRectangle> line;
            for (int j = 0; _map[i][j]; j++) {
                Raylib::RayRectangle rayRect(rect.width, rect.height);
                x = j * _interval + _startX;
                y = i * _interval + _startY;
                rayRect.setPosition(x, y);
                line.push_back(rayRect);
            }
            _rectArr.push_back(line);
        }
    }

    void Grind::drawMap(void)
    {
        char c = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < _map.size(); i++) {
            for (int j = 0; (_map[i])[j]; j++) {
                c = (_map[i])[j];
                x = j * _interval + _startX;
                y = i * _interval + _startY;
                (_typeWall[c])->draw(x, y, BEIGE);
            }
        }
    }

    void Grind::setCoordonate(int x, int y, int interval)
    {
        _startX = x;
        _startY = y;
        _interval = interval;
    }

    std::vector<std::string> Grind::getMap(void)
    {
        return (_map);
    }

    void Grind::setWall(Raylib::Texture *text, char c)
    {
        _typeWall[c] = text;
    }

    void Grind::initMap(void)
    {
        std::string str;
        for (int i = 0; i < _y; i++) {
            str = "";
            for (int j = 0; j < _x; j++) {
                str += " ";
            }
            _map.push_back(str);
        }
    }

    void Grind::setSize(int x, int y)
    {
        _x = x;
        _y = y;
    }

    Grind::Grind()
    {
        _x = 0;
        _y = 0;
        _startX = 0;
        _startY = 0;
        _interval = 0;
    }

    Grind::~Grind()
    {
    }

};