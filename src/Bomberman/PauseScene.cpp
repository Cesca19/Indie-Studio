/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** PauseScene
*/

#include "Bomberman.hpp"

void pauseLoop(Engine::Scene *scene, Raylib::Window *win)
{
    Raylib::setTargetFPS(60);
    while (scene->shouldContinue()) {
        scene->playMusic();
        Raylib::beginDrawing();
     
        scene->Display(win);
        Raylib::endDrawing();
    }
}

std::shared_ptr<Engine::Scene> createPauseScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> PauseScene(new Engine::Scene("Pause"));

    PauseScene->setBackground("../Sprite/wallpapers/playerpresentation.png");
    PauseScene->setLoop(&pauseLoop, win);
    PauseScene->setMusicToplay("MenuMusic");
    addPauseButton(PauseScene.get(), win);
    return PauseScene;
}

void addPauseButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::SpriteButton> Play(new Engine::SpriteButton("Play", "soloGame"));
    std::shared_ptr<Engine::SpriteButton> NewGame(new Engine::SpriteButton("NewGame", "GameMode"));
    std::shared_ptr<Engine::SpriteButton> Settings(new Engine::SpriteButton("Settings", "Settings"));

    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));

    Play->addState("../Sprite/buttons/Play0.png");
    Play->addState("../Sprite/buttons/Play1.png");
    Play->addState("../Sprite/buttons/Play2.png");
    Play->resize(300, 90);
    Play->setPosition(470, 100);
    Play->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Play);

    NewGame->addState("../Sprite/buttons/newgame0.png");
    NewGame->addState("../Sprite/buttons/newgame1.png");
    NewGame->addState("../Sprite/buttons/newgame2.png");
    NewGame->resize(300, 90);
    NewGame->setPosition(470, 300);
    NewGame->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(NewGame);
    
    Settings->addState("../Sprite/buttons/settings0.png");
    Settings->addState("../Sprite/buttons/settings1.png");
    Settings->addState("../Sprite/buttons/settings2.png");
    Settings->resize(300, 90);
    Settings->setPosition(470, 500);
    Settings->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Settings);
    
    Home->addState("../Sprite/buttons/home0.png");
    Home->addState("../Sprite/buttons/home1.png");
    Home->addState("../Sprite/buttons/home2.png");
    Home->resize(50, 50);
    Home->setPosition(1090, 10);
    Home->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Home);
    
    Help->addState("../Sprite/buttons/help0.png");
    Help->addState("../Sprite/buttons/help1.png");
    Help->addState("../Sprite/buttons/help2.png");
    Help->resize(50, 50);
    Help->setPosition(1030, 10);
    Help->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Help);

    Params->addState("../Sprite/buttons/params0.png");
    Params->addState("../Sprite/buttons/params1.png");
    Params->addState("../Sprite/buttons/params2.png");
    Params->resize(50, 50);
    Params->setPosition(970, 10);
    Params->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Params);

    Close->addState("../Sprite/buttons/close0.png");
    Close->addState("../Sprite/buttons/close1.png");
    Close->addState("../Sprite/buttons/close2.png");
    Close->resize(50, 50);
    Close->setPosition(1150, 10);
    Close->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Close);
}