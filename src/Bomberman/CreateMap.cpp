/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** CreateMap
*/

#include "../../include/Bomberman/Bomberman.hpp"

int checkWallRect(Rectangle rayRect)
{
    Vector2 position = Raylib::getMousePosition();
    Raylib::RayRectangle rect(rayRect.width, rayRect.height);

    rect.setPosition(rayRect.x, rayRect.y);
    if (rect.pointOnRayRectangle(position)
    && (Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT) ||  Raylib::isMouseButtonPressed(MOUSE_BUTTON_RIGHT)))
        return (2);
    if (rect.pointOnRayRectangle(position)
    && (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonDown(MOUSE_BUTTON_RIGHT)))
        return (2);
    if (!rect.pointOnRayRectangle(position))
        return (0);
    if(rect.pointOnRayRectangle(position))
        return (1);
        
    return (0);
}

char checkWallArr(std::vector<Raylib::Texture *> arrWall, std::unordered_map<Raylib::Texture *, char>mapWall, int *surr)
{
    int status = 0;
    char c = 0;

    for (int i = 0; i < arrWall.size(); i++) {
        status = checkWallRect((arrWall[i]->getRectangle()));
        if (status) {
            DrawRectangleLines(arrWall[i]->getRectangle().x, arrWall[i]->getRectangle().y, 30, 30, GREEN);
        }
        if (status == 2)
            *surr = i;
    }
    if (*surr >= 0) {
        DrawRectangleLines(arrWall[*surr]->getRectangle().x, arrWall[*surr]->getRectangle().y, 30, 30, BLUE);
        c = mapWall[arrWall[*surr]];
    }
    return (c);
}

void createMapLoop(Engine::Scene *scene, Raylib::Window *win)
{
    int surronded = 1;

    Raylib::Texture wall1;
    Raylib::Texture wall2;
    Raylib::Texture wall3;
    Raylib::Texture *current = NULL;
    std::unordered_map<Raylib::Texture *, char> mapWall;
    std::vector<Raylib::Texture *> arrWall;
    char c = ' ';

    Engine::Grind grind;
    std::vector<std::string> map;

    mapWall[&wall1] = ' ';
    mapWall[&wall3] = 'c';
    mapWall[&wall2] = 'x';

    arrWall.push_back(&wall1);
    arrWall.push_back(&wall3);
    arrWall.push_back(&wall2);
    
    grind.setSize(30, 15);
    grind.initMap();
    wall1.loadTexture("../Sprite/map/wall1.png");
    wall1.resize(30, 30);
    wall1.setPosition(10, 200);
    wall2.loadTexture("../Sprite/map/wall2.png");
    wall2.resize(30, 30);
    wall2.setPosition(10, 250);
    wall3.loadTexture("../Sprite/map/wall3.png");
    wall3.resize(30, 30);
    wall3.setPosition(10, 300);

    grind.setWall(&wall2, 'x');
    grind.setWall(&wall1, ' ');
    grind.setWall(&wall3, 'c');
    grind.setCoordonate(200, 100, 30);

    grind.initRect();
    while (scene->shouldContinue() && !Raylib::isKeyDown(KEY_ENTER)) {
        Raylib::beginDrawing();
        scene->Display(win);
        Raylib::drawText("PRESS ENTER TO SET THE NAME", 40, 40, 50, GRAY);
        scene->playMusic();
        grind.drawMap();
        grind.drawRect(c);
        wall1.draw(10, 200, BEIGE);
        wall2.draw(10, 250, BEIGE);
        wall3.draw(10, 300, BEIGE);
        c = checkWallArr(arrWall, mapWall, &surronded);
        c = ((!c) ? ' ' : c);
        Raylib::endDrawing();
    }
    map = grind.getMap();
    setMapName(win, scene, map);
}

std::shared_ptr<Engine::Scene> createCreateMapScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> createMap(new Engine::Scene("CreateMap"));

    createMap->setBackground("../Sprite/wallpapers/back.png");
    createMap->setLoop(&createMapLoop, win);
    addCreateMapButton(createMap.get(), win);
    createMap->setMusicToplay("MenuMusic");
    return createMap;
}

void addCreateMapButton(Engine::Scene *scene, Raylib::Window *win)
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