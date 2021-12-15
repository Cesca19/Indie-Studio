/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** HelpScene
*/

#include "../../include/Bomberman/Bomberman.hpp"
#include <fstream>
#include <string>

void fillHelpWord(std::vector<std::vector<std::string>> arr, Engine::Scene *scene)
{
    std::shared_ptr<Engine::Entity> entity;
    Color color;

    for (int i = 0; i < arr.size(); i++) {
        entity = scene->createWord("INFO");
        color = Raylib::getColor((arr[i])[3]);
        scene->setEntityPosition(entity, std::stoi((arr[i])[1]), std::stoi((arr[i])[2]), 0);
        scene->setEntityWrite(entity, "../Fonts/Arista20AlternateRegular-jy89.ttf", (arr[i])[0], color, 20);
    }
}

void helpLoop(Engine::Scene *scene, Raylib::Window *win)
{
    std::ifstream stream("../conf/help1.conf");
    std::string file;
    std::vector<std::string> tmp;
    std::vector<std::vector<std::string>> arr;
    std::string line;
    std::vector<std::shared_ptr<Engine::Entity>> *entities = scene->getAllEntities();

    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            tmp = cut_str_del(line);
            arr.push_back(tmp);
        }
    }
    fillHelpWord(arr, scene);
    Raylib::setTargetFPS(60);
    while (scene->shouldContinue()) {
        scene->playMusic();
        Raylib::beginDrawing();
        for (int i = 0; i < (*entities).size(); i++)
            (*entities)[i]->draw();
        scene->Display(win);
        Raylib::endDrawing();
    }  
}

std::shared_ptr<Engine::Scene> createHelpScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> helpScene(new Engine::Scene("Help"));

    helpScene->setBackground("../Sprite/wallpapers/help.png");
    helpScene->setLoop(&helpLoop, win);
    helpScene->setMusicToplay("MenuMusic");
    addHelpButton(helpScene.get(), win);
    return helpScene;
}


void addHelpButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));

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
