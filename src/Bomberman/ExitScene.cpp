/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ExitScene
*/

#include "Bomberman.hpp"

void exitLoop(Engine::Scene *scene, Raylib::Window *win)
{
    int framesCounter = 0;
    int back = 0;

    std::shared_ptr<Engine::Entity> entity = scene->createWord("Ask");
    scene->setEntityPosition(entity, 100, 200, 0);
    scene->setEntityWrite(entity, "../Fonts/Arista20AlternateRegular-jy89.ttf", "Do you want to quit the game ?", WHITE, 60);

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
        entity->draw();
        scene->Display(win);
        Raylib::endDrawing();
    }
}

std::shared_ptr<Engine::Scene> createExitScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> exitScene(new Engine::Scene("Exit"));

    exitScene->setBackground("../Sprite/wallpapers/bomberman0.png");
    exitScene->setLoop(&exitLoop, win);
    exitScene->setMusicToplay("MenuMusic");
    addExitButton(exitScene.get(), win);
    return exitScene;
}

void addExitButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::TextButton> YesBtn(new Engine::TextButton("YesBtn", "Close"));
    std::shared_ptr<Engine::TextButton> NoBtn(new Engine::TextButton("NoBtn", "main"));
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));

    YesBtn->setPosition(Vector2{450, 400});
    YesBtn->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    YesBtn->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    YesBtn->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    YesBtn->setTextSize(40);
    YesBtn->setText("YES");
    YesBtn->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");

    NoBtn->setPosition(Vector2{750, 400});
    NoBtn->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    NoBtn->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    NoBtn->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    NoBtn->setTextSize(40);
    NoBtn->setText("NO");
    NoBtn->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");

    Close->addState("../Sprite/buttons/close0.png");
    Close->addState("../Sprite/buttons/close1.png");
    Close->addState("../Sprite/buttons/close2.png");
    Close->resize(50, 50);
    Close->setPosition(1150, 10);
    Close->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");

    Home->addState("../Sprite/buttons/home0.png");
    Home->addState("../Sprite/buttons/home1.png");
    Home->addState("../Sprite/buttons/home2.png");
    Home->resize(50, 50);
    Home->setPosition(1090, 10);
    Home->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");

    Help->addState("../Sprite/buttons/help0.png");
    Help->addState("../Sprite/buttons/help1.png");
    Help->addState("../Sprite/buttons/help2.png");
    Help->resize(50, 50);
    Help->setPosition(1030, 10);
    Help->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");

    Params->addState("../Sprite/buttons/params0.png");
    Params->addState("../Sprite/buttons/params1.png");
    Params->addState("../Sprite/buttons/params2.png");
    Params->resize(50, 50);
    Params->setPosition(970, 10);
    Params->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Params);

    scene->addButton(YesBtn);
    scene->addButton(NoBtn);
    scene->addButton(Close);
    scene->addButton(Help);
    scene->addButton(Home);
}