/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** ChooseMapScene
*/

#include "Bomberman.hpp"
#include <fstream>
#include <string>

void ChooseMapBattleLoop(Engine::Scene *scene, Raylib::Window *win)
{
    double timer = GetTime();
    int i = 0;
    Camera camera { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    std::vector<std::string> mapName = initMapName();
    std::vector<std::vector<std::string>> mapArr = fillAllMap(mapName);
    Raylib::RayImage wall, ground;
    Raylib::Texture wallText, groundText;
    Raylib::RayModel groundNorm(0), wallNorm(0), wallCass(0);
    Raylib::RayMesh groundNormMesh, wallNormMesh, wallCassMesh;
    Raylib::Texture normText, cassText;
    Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };

    Raylib::setCameraMode(camera, CAMERA_FREE);
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
            scene->launchScene("duoGame");
        }
    }
}

std::shared_ptr<Engine::Scene> createChooseMapBattleScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> scene(new Engine::Scene("ChooseMapBattle"));

    scene->setLoop(&ChooseMapBattleLoop, win);
    scene->setMusicToplay("PlayerPresentationMusic");
    addChooseMapButton(scene.get());
    return scene;
}