/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SpriteButton
*/

#include "SpriteButton.hpp"

namespace Engine{

    void SpriteButton::setTargetScene(std::string scene)
    {
        _targetScene = scene;
    }

    void SpriteButton::setMapScene(void *mapScene)
    {
        //_mapScene = mapScene;
        _mapScene = (std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *)mapScene;
    }

    std::string SpriteButton::getName()
    {
        return _name;
    }

    void SpriteButton::draw(void)
    {
        updateState();
        if (_currentState)
            _currentState->draw(_pos.x, _pos.y, BEIGE);
    }

    void SpriteButton::resize(int width, int height)
    {
        for (int i = 0; i < _stateArray.size(); i++)
            _stateArray[i]->resize(width, height);
    }

    void SpriteButton::setSize(int size)
    {
        _sizeButton = size;
    }

    int SpriteButton::getSize(void) const
    {
        return (_sizeButton);
    }

    Vector2 SpriteButton::getPosition(void) const
    {
        return (_pos);
    }

    void SpriteButton::setPosition(Vector2 pos)
    {
        _pos = pos;
        for (int i = 0; i < _stateArray.size(); i++)
            _stateArray[i]->setPosition(pos);
    }

    void SpriteButton::setPosition(float x, float y)
    {
        _pos.x = x;
        _pos.y = y;
        for (int i = 0; i < _stateArray.size(); i++)
            _stateArray[i]->setPosition(x, y);
    }

    int SpriteButton::checkState(void)
    {
        Vector2 position = Raylib::getMousePosition();
        Rectangle rect = _currentState->getRectangle();

        if (CheckCollisionPointRec(position, rect)
        && (Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT)
        ||  Raylib::isMouseButtonPressed(MOUSE_BUTTON_RIGHT)))
            return (2);
        else if (CheckCollisionPointRec(position, rect)
        && (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT)
        ||  Raylib::isMouseButtonDown(MOUSE_BUTTON_RIGHT)))
            return (2);
        if (!CheckCollisionPointRec(position, rect))
            return (0);
        if (CheckCollisionPointRec(position, rect))
            return (1);
        return (0);
    }

    void SpriteButton::updateState(void)
    {
        //auto var;
        //Raylib::Window *win;
        int ret = checkState();

        _currentState = _stateArray[ret].get();
        switch (ret)
        {
        case 0:
            if (_state == 2 && _targetScene != "") {
                _state = ret;
                (*_mapScene)[_targetScene]->launchLoop();
            }
          //  else if (_is_func_set && _state == 2)
        //    (win->*_function)();
            break;
        case 1:
            if ( _state == 2 && _targetScene != "") {
                _state = ret;
                (*_mapScene)[_targetScene]->launchLoop();
            }
            //    _scene->launchLoop();
          //  else if (_is_func_set && _state == 2)
            //    (win->*_function)();
            if (_ishover != "" && _state == 0)
                _ishoverSound->playSound();
            break;
        case 2:
            if (_isclick != "" && ret != _state)
                _isClickSound->playSound();
            break;
        }
        _state = ret;
    }

    void SpriteButton::addState(std::string path)
    {
        std::shared_ptr<Raylib::Texture> text(new Raylib::Texture(1));

        text->loadTexture(path);
        _stateArray.push_back(text);
        _stateSize += 1;
        if (_stateSize == 1)
            _currentState = text.get();
    }

    SpriteButton::SpriteButton(std::string name, std::string target) : _name(name)
    {
        _currentState = NULL;
        _sizeButton = 40;
        _stateSize = 0;
        _width = 0;
        _height = 0;
        std::shared_ptr<Raylib::Raysound> tmphover(new Raylib::Raysound());
        std::shared_ptr<Raylib::Raysound> tmpclick(new Raylib::Raysound());
        
        _ishoverSound = tmphover;
        _isClickSound = tmpclick;
        _state = 0;
        _is_scene_set = 0;
        _mapScene = NULL;
        _targetScene = target;
       // _is_func_set = 0;
    }

    SpriteButton::~SpriteButton()
    {
    }

    void SpriteButton::setSound(std::string ishover, std::string isclick)
    {
        _ishover = ishover;
        _isclick = isclick;

        _ishoverSound->loadSound(_ishover.c_str());
        _isClickSound->loadSound(_isclick.c_str());
    }

    void SpriteButton::setLinkScene(void *link)
    {
        _is_scene_set = 1;
        //_scene = (Engine::Scene *)link;
    }

    /*void SpriteButton::setLinkFunc(void (Raylib::Window:: *function) ())
    {
        _is_func_set = 1;
        _function = function;
    }*/
};