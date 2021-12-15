/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ChooseMapScene
*/

#include "../../include/Bomberman/Bomberman.hpp"
#include <fstream>
#include <string>

std::vector<std::vector<std::string>> fillAllMap(std::vector<std::string> _mapName)
{
    std::vector<std::vector<std::string>> _mapArr;

    for (int i = 0; i < _mapName.size(); i++) {
        std::vector<std::string> arr;
        std::ifstream stream("../src/Bomberman/Map/" + _mapName[i]);
        std::string line;

        if (stream.is_open()) {
            while (std::getline(stream, line))
                arr.push_back(line);
        stream.close();
        }
        _mapArr.push_back(arr);
    }

        // for (int i = 0; i < _mapArr.size(); i++) {
        //     std::cout << "Sa GAME NO HAJIME DESUKA" << std::endl;
        //     for (int j = 0; j < _mapArr[i].size(); j++)
        //         std::cout << _mapArr[i][j] << std::endl;
        // }
    return (_mapArr);
}

std::vector<std::string> initMapName(void)
{
    std::string tmp;
    std::vector<std::string> _mapName;

    system("ls ../src/Bomberman/Map > ./name.txt");
    std::ifstream stream("./name.txt");

    if (stream.is_open()) {
        while (std::getline(stream, tmp))
            _mapName.push_back(tmp);
        stream.close();
    }
        // for (int i = 0; i < _mapName.size(); i++)
        //     std::cout << _mapName[i] <<std::endl;
    remove("./name.txt");
    return (_mapName);
}

void updateI(int *i, std::vector<std::string> *mapName)
{
    int change = 0;
    static double seconde = 0;
    double timer = GetTime();

    if (timer - seconde < 0.10)
        return;
    seconde = timer;
    if (Raylib::isKeyDown(KEY_LEFT))
        change = -1;
    if (Raylib::isKeyDown(KEY_RIGHT))
        change = 1;
    if (change == -1 && *i == 0)
        *i = mapName->size() - 1;
    else if (change == 1 && *i == mapName->size() - 1)
        *i = 0;
    else
        *i += change;
}

void drawMap(Raylib::RayModel &groundNorm, Raylib::RayModel &wallNorm, Raylib::RayModel &wallCass, std::vector<std::string> arr,Vector3 position)
{
    Vector3 mapPosition = position;
    int i = 0;
    int j = 0;

    for (j = 0; j < arr.size(); j++) {
        for (i = 0; arr[j][i]; i++) {
            groundNorm.draw(mapPosition, 1.0f, WHITE);
            mapPosition.x += 1;
        }
        mapPosition.x = -16.0f;
        mapPosition.z += 1;
    }
    mapPosition = position;
    for (j = 0; j < arr.size(); j++) {
        for (i = 0; arr[j][i]; i++) {
            if (arr[j][i] == 'x')
                wallNorm.draw(mapPosition, 1.0f, WHITE);
            else if (arr[j][i] == 'c')
                wallCass.draw(mapPosition, 1.0f, WHITE);
            mapPosition.x += 1;
        }
        mapPosition.x = -16.0f;
        mapPosition.z += 1;
    }
}

void ChooseMapLoop(Engine::Scene *scene, Raylib::Window *win)
{
    double timer = GetTime();
    int i = 0;
    Camera camera { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    std::vector<std::string> mapName = initMapName();
    std::vector<std::vector<std::string>> mapArr = fillAllMap(mapName);
    //std::vector<std::string> *mapName = scene->getMapName();
    //std::vector<std::vector<std::string>> *mapArr = scene->getMapArr();
    Raylib::RayImage wall;
    Raylib::RayImage ground;
    Raylib::Texture wallText;
    Raylib::Texture groundText;
    Raylib::RayModel groundNorm(0);
    Raylib::RayModel wallNorm(0);
    Raylib::RayModel wallCass(0);
    Raylib::RayMesh groundNormMesh;
    Raylib::RayMesh wallNormMesh;
    Raylib::RayMesh wallCassMesh;
    Raylib::Texture normText;
    Raylib::Texture cassText;
    Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };

    SetCameraMode(camera, CAMERA_FREE);

    scene->setBackground(RAYWHITE);

    wall.loadImage("../Sprite/map/white.png");
    ground.loadImage("../Sprite/map/black.png");

    wallText.loadTextureFromImage(wall.getImage());
    groundText.loadTextureFromImage(ground.getImage());

    wallNormMesh.genMeshCubicmap(wall.getImage(), (Vector3){ 1.0f, 1.0f, 1.0f });
    wallCassMesh.genMeshCubicmap(wall.getImage(), (Vector3){ 1.0f, 1.0f, 1.0f });
    groundNormMesh.genMeshCubicmap(ground.getImage(), (Vector3){ 1.0f, 1.0f, 1.0f });

    wallNorm.load(wallNormMesh);
    wallCass.load(wallCassMesh);
    groundNorm.load(groundNormMesh);
    
    normText.loadTexture("../Sprite/map/block5.png");
    cassText.loadTexture("../Sprite/map/block4.png");

    wallNorm.setTexture(normText);
    groundNorm.setTexture(normText);
    wallCass.setTexture(cassText);

    while (scene->shouldContinue()) {
        updateI(&i, &mapName);
        Raylib::updateCamera(&camera);
        Raylib::beginDrawing();
        scene->playMusic();
        scene->Display(win);
        Raylib::drawText("Choose your map", 100, 10, 50, BLACK);
        Raylib::drawText((mapName)[i], 400, 500, 30, BLACK);
        Raylib::beginMode3D(camera);
        drawMap(groundNorm, wallNorm, wallCass, (mapArr)[i], mapPosition);
        Raylib::endMode3D();
        Raylib::endDrawing();
        if (Raylib::isKeyDown(KEY_ENTER) && GetTime() - timer >= 0.2) {
            scene->selectMap(mapArr[i]);
            scene->launchScene("soloGame");
        }
    }
}

std::shared_ptr<Engine::Scene> createChooseMapScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> scene(new Engine::Scene("ChooseMap"));

    //scene->setBackground("../Sprite/wallpapers/help.png");
    scene->setLoop(&ChooseMapLoop, win);
    scene->setMusicToplay("PlayerPresentationMusic");
    addChooseMapButton(scene.get());
    return scene;
}

void addChooseMapButton(Engine::Scene *scene)
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