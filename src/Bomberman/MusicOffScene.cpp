/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MusicOffScene
*/

#include "Bomberman.hpp"

void musicOffLoop(Engine::Scene *scene, Raylib::Window *win)
{
    scene->pauseMusic();
}

std::shared_ptr<Engine::Scene> createMusicOffScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> musicOffScene (new Engine::Scene("MusicOff"));

    musicOffScene->setLoop(&musicOffLoop, win);
    return musicOffScene;
}