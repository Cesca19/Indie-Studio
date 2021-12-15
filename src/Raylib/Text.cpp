/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Text
*/

#include "../../include/Raylib/Text.hpp"

namespace Raylib
{
    void Text::drawTextRec(RayRectangle rec, float spacing, bool wordWrap)
    {
        DrawTextRec(_font, _content.c_str(), rec.getRect(), _size, spacing, wordWrap, _color);
    }

    Text::Text(bool isAuto)
    {
        _isAuto = isAuto;
        _spacing = 0;
    }

    Text::~Text()
    {
        if (!_isAuto)
            UnloadFont(_font);
    }

    void Text::setText(std::string content)
    {
        _content = content;
    }

    void Text::setFont(std::string path)
    {
        _font = LoadFont(path.c_str());
    }

    Font Text::getFont()
    {
        return (_font);
    }

    void Text::setFontSize(int size)
    {
        _size = size;
    }

    int Text::getFontSize()
    {
        return (_size);
    }

    void Text::setPosition(Vector2 position)
    {
        _position = position;
    }

    Vector2 Text::getPosition()
    {
        return (_position);
    }

    void Text::setSpacing(int spacing)
    {
        _spacing = spacing;
    }

    int Text::getSpacing()
    {
        return (_spacing);
    }

    void Text::setColor(Color color)
    {
        _color = color;
    }

    Vector2 Text::getTextSize()
    {
        return (MeasureTextEx(_font, _content.c_str(), _size, _spacing));
    }

    void Text::draw()
    {
        DrawTextEx(_font, _content.c_str(), _position, _size, _spacing, _color);
    }

};