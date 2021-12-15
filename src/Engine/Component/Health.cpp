/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Health
*/

#include "Health.hpp"

namespace Engine {
    void Health::display()
    {
        int i = _current - 1;
        if (i < 0 || i > 4)
            return;
        //_name.setPosition(Vector2{5, 55});
        //_name.draw();
        _health[i]->draw(_x, _y, WHITE);
    }

    void Health::setPosition(int x, int y)
    {
        _x = x;
        _y = y;
        _name.setPosition(Vector2{(float)_x - 70, (float)_y});
    }

    Health::Health(int max)
    {
        _x = 100;
        _y = 100;
        _max = max;
        _current = 5;

        std::shared_ptr<Raylib::Texture> texture1(new Raylib::Texture);
        std::shared_ptr<Raylib::Texture> texture2(new Raylib::Texture);
        std::shared_ptr<Raylib::Texture> texture3(new Raylib::Texture);
        std::shared_ptr<Raylib::Texture> texture4(new Raylib::Texture);
        std::shared_ptr<Raylib::Texture> texture5(new Raylib::Texture);

        texture1->loadTexture("../Sprite/vie1.png");
        texture2->loadTexture("../Sprite/vie2.png");
        texture3->loadTexture("../Sprite/vie3.png");
        texture4->loadTexture("../Sprite/vie4.png");
        texture5->loadTexture("../Sprite/vie5.png");

        texture1->resize(100, 30);
        texture2->resize(100, 30);
        texture3->resize(100, 30);
        texture4->resize(100, 30);
        texture5->resize(100, 30);

        _health.push_back(texture1);
        _health.push_back(texture2);
        _health.push_back(texture3);
        _health.push_back(texture4);
        _health.push_back(texture5);
    }

    void Health::setCurrentHealth(int health)
    {
        _current = health;
    }

    void Health::setMaxHealth(int health)
    {
        _max = health;
    }

    int Health::getCurrentHealth() const
    {
        return (_current);
    }

    int Health::getMaxHealth() const
    {
        return (_max);
    }

    Health::~Health()
    {
    }
};