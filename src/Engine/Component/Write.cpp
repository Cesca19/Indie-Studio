/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Write
*/

#include "../../../include/Engine/Component/Write.hpp"

namespace Engine {
    int Write::getSize()
    {
        return _size;
    }

    std::shared_ptr<Raylib::Text> Write::getText()
    {
        return _text;
    }

    Write::Write(std::string font_name, std::string content) : _text(new Raylib::Text()), _font(font_name), _content(content)
    {
        _text->setFont(_font);
        _text->setText(_content);
    }

    Write::~Write()
    {
    }

    void Write::setContent(std::string content)
    {
        _content = content;
        _text->setText(_content);
    }

    void Write::setFont(std::string font_name)
    {
        _font = font_name;
        _text->setFont(_font);
    }

    void Write::setColor(Color color)
    {
        _color = color;
        _text->setColor(color);
    }

    void Write::setSize(int size)
    {
        _size = size;
        _text->setFontSize(size);
    }

    std::string Write::getContent() const
    {
        return (_content);
    }

    std::string Write::getFont() const
    {
        return (_font);
    }

    Color Write::getColor()
    {
        return _color;
    }
}