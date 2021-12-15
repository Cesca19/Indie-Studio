/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MusicOnScene
*/

#include "../../include/Bomberman/Bomberman.hpp"

void musicOnLoop(Engine::Scene *scene, Raylib::Window *win)
{
    scene->resumeMusic();
}

std::shared_ptr<Engine::Scene> createMusicOnScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> musicOnScene (new Engine::Scene("MusicOn"));

    musicOnScene->setLoop(&musicOnLoop, win);
    return musicOnScene;
}