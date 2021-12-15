/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SettingsScene
*/

#include "Bomberman.hpp"

void settingsLoop(Engine::Scene *scene, Raylib::Window *win)
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

std::shared_ptr<Engine::Scene> createSettingsScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> settingsScene (new Engine::Scene("Settings"));

    settingsScene->setBackground("../Sprite/wallpapers/bomberman0.png");
    settingsScene->setLoop(&settingsLoop, win);
    settingsScene->setMusicToplay("MenuMusic");
    addSettingsButton(settingsScene.get(), win);
    return settingsScene;
}


void addSettingsButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::TextButton> MusicOn(new Engine::TextButton("MusicOn", "MusicOn"));
    std::shared_ptr<Engine::TextButton> MusicOff(new Engine::TextButton("MusicOff", "MusicOff"));
    std::shared_ptr<Engine::TextButton> FullscreenOn(new Engine::TextButton("FullscreenOn", "FullscreenOn"));
    std::shared_ptr<Engine::TextButton> FullscreenOff(new Engine::TextButton("FullscreenOff", "FullscreenOff"));
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));

    MusicOn->setText("Music On");
    MusicOn->setTextSize(40);
    MusicOn->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    MusicOn->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    MusicOn->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    MusicOn->setPosition(Vector2{200, 250});
    MusicOn->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(MusicOn);
    MusicOff->setText("Music Off");
    MusicOff->setTextSize(40);
    MusicOff->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    MusicOff->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    MusicOff->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    MusicOff->setPosition(Vector2{800, 250});
    MusicOff->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(MusicOff);
    FullscreenOn->setText("Fullscreen On");
    FullscreenOn->setTextSize(40);
    FullscreenOn->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    FullscreenOn->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    FullscreenOn->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    FullscreenOn->setPosition(Vector2{150, 500});
    FullscreenOn->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(FullscreenOn);
    FullscreenOff->setText("Fullscreen Off");
    FullscreenOff->setTextSize(40);
    FullscreenOff->setTextFont("../Fonts/PixelEmulator-xq08.ttf");
    FullscreenOff->setTextColor(Color{160,82,45, 255}, Color{0, 170 ,140, 255}, Color{255,20,100, 255});
    FullscreenOff->setColor(Color{255,218,185, 255}, Color{179,238,238, 255}, Color{255,182,193, 255});
    FullscreenOff->setPosition(Vector2{750, 500});
    FullscreenOff->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(FullscreenOff);
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
}