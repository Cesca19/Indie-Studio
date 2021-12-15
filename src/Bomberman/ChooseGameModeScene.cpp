/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ChooseGameModeScene
*/

#include "Bomberman.hpp"

void gameModeLoop(Engine::Scene *scene, Raylib::Window *win)
{
    while (scene->shouldContinue()) {
        scene->playMusic();
        Raylib::beginDrawing();
        scene->getEntity("Choose Game Mode")->draw();
        scene->Display(win);
        Raylib::endDrawing();
    }  
}


std::shared_ptr<Engine::Scene> createGameModeScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> GameModeScene(new Engine::Scene("GameMode"));
    
    GameModeScene->setBackground("../Sprite/wallpapers/gameMode.png");
    GameModeScene->setLoop(gameModeLoop, win);
    GameModeScene->setMusicToplay("PlayerPresentationMusic");
    addGameModeButton(GameModeScene.get(), win);
    return GameModeScene;
}

void addGameModeButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));
    std::shared_ptr<Engine::TextButton> battle(new Engine::TextButton("BattleMode", "BattlePlayerPresentation"));
    std::shared_ptr<Engine::TextButton> solo(new Engine::TextButton("SoloMode", "playerPresentation"));

    std::shared_ptr<Engine::Entity> entity = scene->createWord("Choose Game Mode");
    scene->setEntityPosition(entity, 200, 100, 0);
    scene->setEntityWrite(entity, "../Fonts/bomberman.TTF", "Choose a Game Mode !!!!!", WHITE, 60);

    Close->addState("../Sprite/buttons/close0.png");
    Close->addState("../Sprite/buttons/close1.png");
    Close->addState("../Sprite/buttons/close2.png");
    Close->resize(50, 50);
    Close->setPosition(1150, 10);
    Close->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Close);
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

    battle->setText("Battle Mode");
    battle->setTextSize(40);
    battle->setTextFont("../Fonts/bomberman.TTF");
    battle->setTextColor(Color{255,160,122, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    battle->setColor(BLANK, BLANK, BLANK);
    battle->setPosition(Vector2{500, 430});
    battle->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(battle);

    solo->setText("Solo Mode");
    solo->setTextSize(40);
    solo->setTextFont("../Fonts/bomberman.TTF");
    solo->setTextColor(Color{255,160,122, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    solo->setColor(BLANK, BLANK, BLANK);
    solo->setPosition(Vector2{520, 300});
    solo->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(solo);
}