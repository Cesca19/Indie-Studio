/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MainScene
*/

#include "Bomberman.hpp"

void mainLoop(Engine::Scene *scene, Raylib::Window *win)
{
    int back = 0;
    int framesCounter = 0;

    Raylib::setTargetFPS(60);
    while (scene->shouldContinue()) {
        scene->playMusic();
        Raylib::beginDrawing();
        framesCounter++;
        if (framesCounter >= (180)) {
            framesCounter = 0;
            back++;
            if (back > 4) back = 0;
            scene->setBackground("../Sprite/wallpapers/bomberman" + std::to_string(back) + ".png");   
        }
        scene->Display(win);
        Raylib::endDrawing();
    }  
}

std::shared_ptr<Engine::Scene> createMainScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> mainScene(new Engine::Scene("main"));
    
    mainScene->setBackground("../Sprite/wallpapers/bomberman0.png");
    mainScene->setLoop(mainLoop, win);
    mainScene->setMusicToplay("MenuMusic");
    addMainButton(mainScene.get(), win);
    return mainScene;
}

void addMainButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::SpriteButton> NewGame(new Engine::SpriteButton("NewGame", "GameMode"));
    std::shared_ptr<Engine::SpriteButton> Settings(new Engine::SpriteButton("Settings", "Settings"));
    std::shared_ptr<Engine::SpriteButton> Exit(new Engine::SpriteButton("Exit", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));
    std::shared_ptr<Engine::SpriteButton> CreateMap( new Engine::SpriteButton("CreateMap", "CreateMap"));

    NewGame->addState("../Sprite/buttons/newgame0.png");
    NewGame->addState("../Sprite/buttons/newgame1.png");
    NewGame->addState("../Sprite/buttons/newgame2.png");
    NewGame->resize(280, 100);
    NewGame->setPosition(470, 200);
    NewGame->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(NewGame);
    
    Settings->addState("../Sprite/buttons/settings0.png");
    Settings->addState("../Sprite/buttons/settings1.png");
    Settings->addState("../Sprite/buttons/settings2.png");
    Settings->resize(300, 100);
    Settings->setPosition(50, 350);
    Settings->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Settings);
    
    Exit->addState("../Sprite/buttons/exit0.png");
    Exit->addState("../Sprite/buttons/exit1.png");
    Exit->addState("../Sprite/buttons/exit2.png");
    Exit->resize(300, 100);
    Exit->setPosition(885, 350);
    Exit->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Exit);
    
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

    scene->addButton(Help);
    CreateMap->addState("../Sprite/buttons/load0.png");
    CreateMap->addState("../Sprite/buttons/load1.png");
    CreateMap->addState("../Sprite/buttons/load2.png");
    CreateMap->resize(300, 100);
    CreateMap->setPosition(450, 450);
    CreateMap->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(CreateMap);
}