/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** BattlePlayerPresentationScene
*/

#include "Bomberman.hpp"

void battlePlayerPresentationLoop(Engine::Scene *scene, Raylib::Window *win)
{
    Camera camera = {{ 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    std::vector<std::string> playerNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
    int numPlayer = 0, player1 = -1;
    static int num = 0;

    Raylib::setTargetFPS(135);
    Raylib::setCameraMode(camera, CAMERA_FREE);
    
    while (scene->shouldContinue()) {
        Raylib::updateCamera(&camera);
        Raylib::beginDrawing();
        if (numPlayer == player1)
            numPlayer++;
        if (Raylib::isKeyPressed(KEY_LEFT)) numPlayer--;
        else if (Raylib::isKeyPressed(KEY_RIGHT)) numPlayer++;
        if (numPlayer < 0) numPlayer = 12;
        else if (numPlayer > 12) numPlayer = 0;
        
        scene->playMusic();
        scene->getEntity("Player" + std::to_string(numPlayer))->draw();
        scene->setEntityWrite(scene->getEntity("PlayerName"), playerNames[numPlayer]);
        scene->setEntityWrite(scene->getEntity("Choose Player"), "Player " + std::to_string(num + 1) + " choose your Avatar !!", 40);
        scene->getEntity("Choose Player")->draw();
        scene->getEntity("PlayerName")->draw();
        scene->Display(win, &camera);
        Raylib::endDrawing();
        if (Raylib::isKeyPressed(KEY_ENTER) && num == 0) {
            std::ofstream file("player" + std::to_string(num) + ".txt");
            file << numPlayer << std::endl;
            player1 = numPlayer;
            num = 1;
            numPlayer = 0;
        } else if (Raylib::isKeyPressed(KEY_ENTER) && num == 1 && player1 != numPlayer) {
            std::ofstream file("player" + std::to_string(num) + ".txt");
            file << numPlayer << std::endl;
            num = 0;
            numPlayer = 0;
            scene->launchScene("ChooseMapBattle");
        }
    }
}

std::shared_ptr<Engine::Scene> createBattlePlayerPresentationScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> battlePlayerPresentationScene(new Engine::Scene("BattlePlayerPresentation"));
    
    battlePlayerPresentationScene->setLoop(battlePlayerPresentationLoop, win);
    battlePlayerPresentationScene->setMusicToplay("PlayerPresentationMusic");
    battlePlayerPresentationScene->setBackground("../Sprite/wallpapers/playerpresentation.png");
    addPlayerPresentationButton(battlePlayerPresentationScene.get(), win);
    createPlayer(battlePlayerPresentationScene.get(), win);
    return battlePlayerPresentationScene;
}