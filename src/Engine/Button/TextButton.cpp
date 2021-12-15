/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** TextButton
*/

#include "TextButton.hpp"

namespace Engine
{

    void TextButton::setMapScene(void *mapScene)
    {
        _mapScene = (std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *)mapScene;
    }

    void TextButton::setTargetScene(std::string scene)
    {
        _targetScene = scene;
    }

    TextButton::TextButton(std::string name, std::string target) :  _rect(100, 50), _ishover(""), _isclick("")
    {
        _name = name;
        std::shared_ptr<Raylib::Raysound> tmphover(new Raylib::Raysound());
        std::shared_ptr<Raylib::Raysound> tmpclick(new Raylib::Raysound());
        
        _ishoverSound = tmphover;
        _isClickSound = tmpclick;
        _current_state = 0;
        _is_scene_set = 0;
        _scene = NULL;
        _mapScene = NULL;
        _targetScene = target;
    }

    TextButton::~TextButton()
    {
    }

    std::string TextButton::getName()
    {
        return _name;
    }

    void TextButton::setPosition(Vector2 position)
    {
        _text.setPosition(position);
        _position = position;
    }

    Vector2 TextButton::getPosition() const
    {
        return (_position);
    }

    void TextButton::setTextSize(int size)
    {
        _text.setFontSize(size);
        _size = size;
    }

    void TextButton::setTextFont(std::string font)
    {
        _text.setFont(font);
        _font = font;
    }

    int TextButton::getTextSize() const
    {
        return (_size);
    }

    void TextButton::setRayRectangle()
    {
        Vector2  size = _text.getTextSize();
        _rect.updRayRectangle(_position.x - 50, _position.y - 15, size.x + 100, size.y + 30);
    }

    int TextButton::checkState()
    {
        
        Vector2 position = Raylib::getMousePosition();

        if (_rect.pointOnRayRectangle(position)
        && (Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT) ||  Raylib::isMouseButtonPressed(MOUSE_BUTTON_RIGHT)))
            return (2);
        if (_rect.pointOnRayRectangle(position)
        && (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonDown(MOUSE_BUTTON_RIGHT)))
            return (2);
        if (!_rect.pointOnRayRectangle(position))
            return (0);
        if(_rect.pointOnRayRectangle(position))
            return (1);
        
        return (0);
    }

    void TextButton::setText(std::string content)
    {
        _text.setText(content);
    }

    void TextButton::draw()
    {
        setRayRectangle();
        updateState();
        _rect.draw(0.8, 0, _current_rect);
        _text.draw();
    }

    void TextButton::updateState()
    {
        int state = checkState();

        switch (state) {
        case 0:
            _text.setColor(_text_sample);
            _current_rect = _button_sample;
            if (_current_state == 2 && _targetScene != "") {
                _current_state = state;
                (*_mapScene)[_targetScene]->launchLoop();
            }
            break;
        case 1:
            if (_ishover != "" && _current_state == 0)
                _ishoverSound->playSound();
            _text.setColor(_text_hover);
            _current_rect = _button_hover;
            if (_current_state == 2 && _targetScene != "") {
                _current_state = state;
                (*_mapScene)[_targetScene]->launchLoop();
            }
            break;
        case 2:
            if (_isclick != "" && state != _current_state)
                _isClickSound->playSound();
            _text.setColor(_text_click);
            _current_rect = _button_click;
            break;
        }
        _current_state = state;
    }

    void TextButton::setTextColor(Color text_sample, Color text_hover, Color text_click)
    {
        _text.setColor(text_sample);
        _text_sample = text_sample;
        _text_hover = text_hover;
        _text_click = text_click;
    }

    void TextButton::setColor(Color button_sample, Color button_hover, Color button_click) {
        
        _button_sample = button_sample;
        _button_hover = button_hover;
        _current_rect = _button_sample;
        _button_click = button_click;
    }
    void TextButton::setSound(std::string ishover, std::string isclick)
    {
        _ishover = ishover;
        _isclick = isclick;

        _ishoverSound->loadSound(_ishover.c_str());
        _isClickSound->loadSound(_isclick.c_str());
    }

    void TextButton::setLinkScene(void *link)
    {
        _is_scene_set = 1;
        _scene = (Engine::Scene *)link;
    }

    /*void TextButton::setLinkFunc(void (*function) ())
    {
        _is_func_set = 1;
        _function = function;
    }*/
}