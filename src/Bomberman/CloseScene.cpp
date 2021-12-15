/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** CloseScene
*/

#include "Bomberman.hpp"

void closeLoop(Engine::Scene *scene, Raylib::Window *win)
{
    scene->closeWindow();
}

std::shared_ptr<Engine::Scene> createCloseScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> closeScene (new Engine::Scene("Close"));

    closeScene->setBackground("../Sprite/bomberman0.png");
    closeScene->setLoop(&closeLoop, win);
    return closeScene;
}