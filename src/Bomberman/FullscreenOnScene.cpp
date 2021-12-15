/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** FullscreenScene
*/

#include "Bomberman.hpp"

void fullscreenOnLoop(Engine::Scene *scene, Raylib::Window *win)
{
    if (!win->isWindowFullscreen())
        win->setFullscreen();
}

std::shared_ptr<Engine::Scene> createFullscreenOnScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> fullscreenOnScene (new Engine::Scene("FullscreenOn"));

    fullscreenOnScene->setLoop(&fullscreenOnLoop, win);
    return fullscreenOnScene;
}