/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** PlayerPresentationScene
*/

#include "Bomberman.hpp"

void playerPresentationLoop(Engine::Scene *scene, Raylib::Window *win)
{
    Camera camera = {{ 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    Raylib::setTargetFPS(135);
    Raylib::setCameraMode(camera, CAMERA_FREE);
    int numPlayer = 0;
    std::vector<std::string> playerNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
    
    
    while (scene->shouldContinue()) {
        Raylib::updateCamera(&camera);
        Raylib::beginDrawing();
        if (Raylib::isKeyPressed(KEY_LEFT)) numPlayer--;
        else if (Raylib::isKeyPressed(KEY_RIGHT)) numPlayer++;
        if (numPlayer < 0) numPlayer = 12;
        else if (numPlayer > 12) numPlayer = 0;
        
        scene->playMusic();
        scene->getEntity("Player" + std::to_string(numPlayer))->draw();
        scene->setEntityWrite(scene->getEntity("PlayerName"), playerNames[numPlayer]);
        scene->getEntity("Choose Player")->draw();
        scene->getEntity("PlayerName")->draw();
        scene->Display(win, &camera);
        Raylib::endDrawing();
        if (Raylib::isKeyPressed(KEY_ENTER)) {
            std::ofstream file("player.txt");
            file << numPlayer << std::endl;
            scene->launchScene("ChooseMap");
        }
    }
}

std::shared_ptr<Engine::Scene> createPlayerPresentationScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> playerPresentationScene(new Engine::Scene("playerPresentation"));
    
    playerPresentationScene->setLoop(playerPresentationLoop, win);
    playerPresentationScene->setMusicToplay("PlayerPresentationMusic");
    playerPresentationScene->setBackground("../Sprite/wallpapers/playerpresentation.png");
    addPlayerPresentationButton(playerPresentationScene.get(), win);
    createPlayer(playerPresentationScene.get(), win);
    return playerPresentationScene;
}

void addPlayerPresentationButton(Engine::Scene *scene, Raylib::Window *win)
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

void createPlayer(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::Entity> entity = scene->createWord("Choose Player");
    scene->setEntityPosition(entity, 200, 100, 0);
    scene->setEntityWrite(entity, "../Fonts/bomberman.TTF", "Choose your Avatar !!!", WHITE, 60);

    std::shared_ptr<Engine::Entity> playerName = scene->createWord("PlayerName");
    scene->setEntityPosition(playerName, 500, 500, 0);
    scene->setEntityWrite(playerName, "../Fonts/bomberman.TTF", "PlayerName", WHITE, 50);

    std::shared_ptr<Raylib::Texture> texture0(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity0 = scene->createSprite("Player0");

    std::shared_ptr<Raylib::Texture> texture1(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity1 = scene->createSprite("Player1");

    std::shared_ptr<Raylib::Texture> texture2(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity2 = scene->createSprite("Player2");

    std::shared_ptr<Raylib::Texture> texture3(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity3 = scene->createSprite("Player3");

    std::shared_ptr<Raylib::Texture> texture4(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity4 = scene->createSprite("Player4");

    std::shared_ptr<Raylib::Texture> texture5(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity5 = scene->createSprite("Player5");

    std::shared_ptr<Raylib::Texture> texture6(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity6 = scene->createSprite("Player6");


    std::shared_ptr<Raylib::Texture> texture7(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity7 = scene->createSprite("Player7");


    std::shared_ptr<Raylib::Texture> texture8(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity8 = scene->createSprite("Player8");

    std::shared_ptr<Raylib::Texture> texture9(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity9 = scene->createSprite("Player9");

    std::shared_ptr<Raylib::Texture> texture10(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity10 = scene->createSprite("Player10");

    std::shared_ptr<Raylib::Texture> texture11(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity11 = scene->createSprite("Player11");


    std::shared_ptr<Raylib::Texture> texture12(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> entity12 = scene->createSprite("Player12");

    texture0->loadTexture("../Sprite/player/white_skin/antenne_rose_t_shirt_violet.png");
    scene->setEntityPosition(entity0, 0, -6, 0);
    scene->setEntityRenderModel(entity0, texture0, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity0, "../Sprite/player/player.iqm", 3);

    texture1->loadTexture("../Sprite/player/white_skin/antenne_noire_t_shirt_cyan.png");
    scene->setEntityPosition(entity1, 0, -6, 0);
    scene->setEntityRenderModel(entity1, texture1, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity1, "../Sprite/player/player.iqm", 3);

    texture2->loadTexture("../Sprite/player/white_skin/antenne_rose_t_shirt_cyan.png");
    scene->setEntityPosition(entity2, 0, -6, 0);
    scene->setEntityRenderModel(entity2, texture2, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity2, "../Sprite/player/player.iqm", 3);

    texture3->loadTexture("../Sprite/player/white_skin/antenne_rose_t_shirt_vert.png");
    scene->setEntityPosition(entity3, 0, -6, 0);
    scene->setEntityRenderModel(entity3, texture3, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity3, "../Sprite/player/player.iqm", 3);

    texture4->loadTexture("../Sprite/player/white_skin/antenne_rouge_t_shirt_jaune.png");
    scene->setEntityPosition(entity4, 0, -6, 0);
    scene->setEntityRenderModel(entity4, texture4, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity4, "../Sprite/player/player.iqm", 3);

    texture5->loadTexture("../Sprite/player/white_skin/antenne_rouge_t_shirt_vert.png");
    scene->setEntityPosition(entity5, 0, -6, 0);
    scene->setEntityRenderModel(entity5, texture5, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity5, "../Sprite/player/player.iqm", 3);

    texture6->loadTexture("../Sprite/player/white_skin/antenne_noire_t_shirt_bleu.png");
    scene->setEntityPosition(entity6, 0, -6, 0);
    scene->setEntityRenderModel(entity6, texture6, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity6, "../Sprite/player/player.iqm", 3);

    texture7->loadTexture("../Sprite/player/brown_skin/antenne_noire_t_shirt_orange.png");
    scene->setEntityPosition(entity7, 0, -6, 0);
    scene->setEntityRenderModel(entity7, texture7, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity7, "../Sprite/player/player.iqm", 3);

    texture8->loadTexture("../Sprite/player/brown_skin/antenne_noire_t_shirt_violet.png");
    scene->setEntityPosition(entity8, 0, -6, 0);
    scene->setEntityRenderModel(entity8, texture8, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity8, "../Sprite/player/player.iqm", 3);

    texture9->loadTexture("../Sprite/player/brown_skin/antenne_rose_t_shirt_cyan.png");
    scene->setEntityPosition(entity9, 0, -6, 0);
    scene->setEntityRenderModel(entity9, texture9, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity9, "../Sprite/player/player.iqm", 3);

    texture10->loadTexture("../Sprite/player/brown_skin/antenne_rose_t_shirt_violet.png");
    scene->setEntityPosition(entity10, 0, -6, 0);
    scene->setEntityRenderModel(entity10, texture10, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity10, "../Sprite/player/player.iqm", 3);

    texture11->loadTexture("../Sprite/player/brown_skin/antenne_rouge_t_shirt_rougeAuVin.png");
    scene->setEntityPosition(entity11, 0, -6, 0);
    scene->setEntityRenderModel(entity11, texture11, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity11, "../Sprite/player/player.iqm", 3);

    texture12->loadTexture("../Sprite/player/brown_skin/antenne_rouge_t_shirt_vert.png");
    scene->setEntityPosition(entity12, 0, -6, 0);
    scene->setEntityRenderModel(entity12, texture12, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{5, 5, 5}, 135, WHITE);
    scene->setEntityRenderModelAnimation(entity12, "../Sprite/player/player.iqm", 3);
}