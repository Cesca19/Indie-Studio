/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "../Raylib/raylib.hpp"
#include "../Engine/Engine.hpp"
#include <fstream>
#include <string>
#include <stdio.h>


std::shared_ptr<Engine::Scene> createStartScene(Raylib::Window *win);
void startLoop(Engine::Scene *scene, Raylib::Window *win);

void addStartButton(Engine::Scene *scene, Raylib::Window *win);

void createDuoPlayer(Engine::Scene *scene, Raylib::Window *win);
void duoGameLoop(Engine::Scene *scene, Raylib::Window *win);
void addDuoGameButton(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createDuoGameScene(Raylib::Window *win);

void updateI(int *i, std::vector<std::string> *mapName);
std::shared_ptr<Engine::Scene> createChooseMapBattleScene(Raylib::Window *win);

std::shared_ptr<Engine::Scene> createBattlePlayerPresentationScene(Raylib::Window *win);

void addCreateMapButton(Engine::Scene *scene, Raylib::Window *win);

std::shared_ptr<Engine::Scene> createBattlePlayerPresentationScene(Raylib::Window *win);
void battlePlayerPresentationLoop(Engine::Scene *scene, Raylib::Window *win);

void drawMap(Raylib::RayModel &groundNorm, Raylib::RayModel &wallNorm, Raylib::RayModel &wallCass, std::vector<std::string> arr,Vector3 position);

std::vector<std::string> initMapName(void);
std::vector<std::vector<std::string>> fillAllMap(std::vector<std::string> _mapName);


void ChooseMapLoop(Engine::Scene *scene, Raylib::Window *win);
void addChooseMapButton(Engine::Scene *scene);
std::vector<std::string> cut_str_del(std::string str, std::string del=";");

std::shared_ptr<Engine::Scene> createChooseMapScene(Raylib::Window *win);

void setMapName(Raylib::Window *win, Engine::Scene *scene, std::vector<std::string> map);

void helpLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createHelpScene(Raylib::Window *win);
void addHelpButton(Engine::Scene *scene, Raylib::Window *win);

void mainLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createMainScene(Raylib::Window *win);
void addMainButton(Engine::Scene *scene, Raylib::Window *win);

void settingsLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createSettingsScene(Raylib::Window *win);
void addSettingsButton(Engine::Scene *scene, Raylib::Window *win);

void exitLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createExitScene(Raylib::Window *win);
void addExitButton(Engine::Scene *scene, Raylib::Window *win);

void closeLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createCloseScene(Raylib::Window *win);

void fullscreenOnLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createFullscreenOnScene(Raylib::Window *win);

void fullscreenOffLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createFullscreenOffScene(Raylib::Window *win);

void musicOnLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createMusicOnScene(Raylib::Window *win);

void musicOffLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createMusicOffScene(Raylib::Window *win);

std::shared_ptr<Engine::Scene> createCreateMapScene(Raylib::Window *win);
void createMapLoop(Engine::Scene *scene, Raylib::Window *win);

void createPlayer(Engine::Scene *scene, Raylib::Window *win);
void playerPresentationLoop(Engine::Scene *scene, Raylib::Window *win);
void addPlayerPresentationButton(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createPlayerPresentationScene(Raylib::Window *win);

void gameModeLoop(Engine::Scene *scene, Raylib::Window *win);
void addGameModeButton(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createGameModeScene(Raylib::Window *win);

void createSoloPlayer(Engine::Scene *scene, Raylib::Window *win);
void soloGameLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createSoloGameScene(Raylib::Window *win);
void addsoloGameButton(Engine::Scene *scene, Raylib::Window *win);

void pauseLoop(Engine::Scene *scene, Raylib::Window *win);
std::shared_ptr<Engine::Scene> createPauseScene(Raylib::Window *win);
void addPauseButton(Engine::Scene *scene, Raylib::Window *win);

#endif /* !BOMBERMAN_HPP_ */
