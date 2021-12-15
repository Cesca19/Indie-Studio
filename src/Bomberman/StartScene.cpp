/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** StartScene
*/

#include "Bomberman.hpp"

void startLoop(Engine::Scene *scene, Raylib::Window *win)
{
    int back = 0;
    int framesCounter = 0;

    std::shared_ptr<Engine::Entity> entity = scene->createWord("Ask");
    Raylib::Texture background;
    Raylib::Texture midground1, midground2, midground3, midground4, midground5;
    Raylib::Texture bomb1, bomb2;
    float scrollingBack = 0.0f;
    float scrollingMid1 = 0.0f, scrollingMid2 = 400.0f, scrollingMid3 = 570.0f, scrollingMid4 = 900.0f, scrollingMid5 = 1250.0f;
    float scrollingbomb1 = 600, scrollingbomb2 = 750;
 
    scene->setEntityPosition(entity, 100, 500, 0);
    scene->setEntityWrite(entity, "../Fonts/bomberman.TTF", "PRESS ENTER ... ", WHITE, 30);
    background.loadTexture("../Sprite/begin/bg.png");
    midground1.loadTexture("../Sprite/begin/circulate.png");
    midground2.loadTexture("../Sprite/begin/plan1.png");
    midground3.loadTexture("../Sprite/begin/plan2.png");
    midground4.loadTexture("../Sprite/begin/plan3.png");
    midground5.loadTexture("../Sprite/begin/plan4.png");
    bomb1.loadTexture("../Sprite/begin/bomb1.png");
    bomb2.loadTexture("../Sprite/begin/bomb2.png");

    Raylib::setTargetFPS(60);
    while (scene->shouldContinue()) {
        scene->playMusic();
        scrollingBack -= 0.1f;
        scrollingMid1 -= 0.2f;
        scrollingMid2 -= 0.10f;
        scrollingMid3 -= 0.10f;
        scrollingMid4 -= 0.10f;
        scrollingMid5 -= 0.10f;
        scrollingbomb1 -= 0.3f;
        scrollingbomb2 -= 0.35f;

        if (scrollingMid1 <= -300) scrollingMid1 = 0;                                                                               
        if (scrollingMid2 <= -300) scrollingMid2 = 1100;                                                                                 
        if (scrollingMid3 <= -1000) scrollingMid3 = 1100;                                                                               
        if (scrollingMid4 <= -1900) scrollingMid4 = 1100;                                                                           
        if (scrollingMid5 <= -2150) scrollingMid5 = 1100;                                                                                
        if (scrollingbomb2 <= -500) scrollingbomb1 = 1100;                                                                               
        if (scrollingbomb1 <= -1300) scrollingbomb2 = 1100; 

        Raylib::beginDrawing();

        background.drawTextureEx((Vector2){scrollingBack, 0}, 0.0f, 1.0f, WHITE);
        midground1.drawTextureEx((Vector2){scrollingMid1, 180}, 0.0f, 1.0f, WHITE);
        midground2.drawTextureEx((Vector2){scrollingMid2, 140}, 0.0f, 0.6f, WHITE);
        midground3.drawTextureEx((Vector2){scrollingMid3, 210}, 0.0f, 1.0f, WHITE);
        midground4.drawTextureEx((Vector2){scrollingMid4, 190}, 0.0f, 0.6f, WHITE);
        midground5.drawTextureEx((Vector2){scrollingMid5, 300}, 0.0f, 0.6f, WHITE);
     
        scene->Display(win);
        Raylib::endDrawing();
        entity->draw();
        if (Raylib::isKeyDown(KEY_ENTER))
            scene->launchScene("main");
    }
}

std::shared_ptr<Engine::Scene> createStartScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> startScene(new Engine::Scene("start"));
    
    //startScene->setBackground("../Sprite/wallpapers/bomberman0.png");
    startScene->setLoop(startLoop, win);
    startScene->setMusicToplay("MenuMusic");
    addStartButton(startScene.get(), win);
    return startScene;
}

void addStartButton(Engine::Scene *scene, Raylib::Window *win)
{
    //std::shared_ptr<Engine::SpriteButton> NewGame(new Engine::SpriteButton("NewGame", "GameMode"));
    //std::shared_ptr<Engine::SpriteButton> Settings(new Engine::SpriteButton("Settings", "Settings"));
    //td::shared_ptr<Engine::SpriteButton> Exit(new Engine::SpriteButton("Exit", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));
    //std::shared_ptr<Engine::SpriteButton> CreateMap( new Engine::SpriteButton("CreateMap", "CreateMap"));
    
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
}