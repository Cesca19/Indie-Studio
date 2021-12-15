/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** main
*/

#include "Bomberman/Bomberman.hpp"
#include "Engine/Engine.hpp"
#include "Raylib/raylib.hpp"
#include <fstream>
#include <string>
#include <vector>

int initCoreScene(Raylib::Window *win, Engine::Core *core)
{
    std::shared_ptr<Engine::Scene> start = createMainScene(win);
    std::shared_ptr<Engine::Scene> settings = createSettingsScene(win);
    std::shared_ptr<Engine::Scene> exit = createExitScene(win);
    std::shared_ptr<Engine::Scene> help = createHelpScene(win);
    std::shared_ptr<Engine::Scene> fullscreenOff = createFullscreenOffScene(win);    
    std::shared_ptr<Engine::Scene> fullscreenOn = createFullscreenOnScene(win);
    std::shared_ptr<Engine::Scene> close = createCloseScene(win); 
    std::shared_ptr<Engine::Scene> musicOff = createMusicOffScene(win);    
    std::shared_ptr<Engine::Scene> musicOn = createMusicOnScene(win);
    std::shared_ptr<Engine::Scene> createMap = createCreateMapScene(win);
    std::shared_ptr<Engine::Scene> playerPresentation = createPlayerPresentationScene(win);
    std::shared_ptr<Engine::Scene> chooseMap = createChooseMapScene(win);
    std::shared_ptr<Engine::Scene> chooseMapBattle = createChooseMapBattleScene(win);
    std::shared_ptr<Engine::Scene> GameMode = createGameModeScene(win);
    std::shared_ptr<Engine::Scene> soloGame = createSoloGameScene(win);
    std::shared_ptr<Engine::Scene> duoGame = createDuoGameScene(win);
    std::shared_ptr<Engine::Scene> Pause = createPauseScene(win);
    std::shared_ptr<Engine::Scene> startScreen = createStartScene(win);
    std::shared_ptr<Engine::Scene> battlepresentation = createBattlePlayerPresentationScene(win);

    std::shared_ptr<Raylib::MusicStream> menuMusic(new Raylib::MusicStream());
    std::shared_ptr<Raylib::MusicStream> playerPresentationMusic(new Raylib::MusicStream());
    std::shared_ptr<Raylib::MusicStream> battleMusic(new Raylib::MusicStream());

    menuMusic->loadMusicStream("../Sounds/main-theme.mp3");
    battleMusic->loadMusicStream("../Sounds/music_battle.ogg");
    playerPresentationMusic->loadMusicStream("../Sounds/music_player_select.ogg");
    core->addMusic(menuMusic, "MenuMusic");
    core->addMusic(battleMusic, "BattleMusic");
    core->addMusic(playerPresentationMusic, "PlayerPresentationMusic");
    core->addScene(start);
    core->addScene(startScreen);
    core->addScene(settings);
    core->addScene(exit);
    core->addScene(help);
    core->addScene(close);
    core->addScene(fullscreenOff);
    core->addScene(fullscreenOn);
    core->addScene(musicOff);
    core->addScene(musicOn);
    core->addScene(createMap);
    core->addScene(playerPresentation);
    core->addScene(chooseMap);
    core->addScene(GameMode);
    core->addScene(soloGame);
    core->addScene(Pause);
    core->addScene(battlepresentation);
    core->addScene(chooseMapBattle);
    core->addScene(duoGame);
    core->setWindow(win);
    return 0;
}

int main(void)
{
    Raylib::Window win(1200, 650, "Bomberman");
    Raylib::initAudioDevice();

    Engine::Core core;
    initCoreScene(&win, &core);
    core.setMainScene("start");
    core.run();

    Raylib::closeAudioDevice();
    return 0;
}