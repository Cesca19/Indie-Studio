/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** FullscreenScene
*/

#include "Bomberman.hpp"

void fullscreenOffLoop(Engine::Scene *scene, Raylib::Window *win)
{
    if (win->isWindowFullscreen())
        win->setFullscreen();
}

std::shared_ptr<Engine::Scene> createFullscreenOffScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> fullscreenOffScene (new Engine::Scene("FullscreenOff"));

    fullscreenOffScene->setLoop(&fullscreenOffLoop, win);
    return fullscreenOffScene;
}