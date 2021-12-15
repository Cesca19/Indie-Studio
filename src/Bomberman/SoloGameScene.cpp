/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SoloGameScene
*/

#include "Bomberman.hpp"

void soloGameLoop(Engine::Scene *scene, Raylib::Window *win)
{
    Camera camera = {{ 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
    std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
    int back = 0, framesCounter = 0, numPlayer = 0, i = 0;
    std::ifstream file("player.txt");
    std::string line;
    double timer = GetTime();
    std::vector<std::string> *map = scene->getMapSelected();
    Raylib::RayImage wall, ground;
    Raylib::Texture wallText, groundText, normText, cassText;
    Raylib::RayModel groundNorm(0), wallNorm(0), wallCass(0);
    Raylib::RayMesh groundNormMesh, wallNormMesh, wallCassMesh;
    Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };
    
    if(file)
        getline(file, line);
    numPlayer = atoi(line.c_str());
    Raylib::setTargetFPS(60);
    SetCameraMode(camera, CAMERA_FREE);

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
    
    createSoloPlayer(scene, win);
    while (scene->shouldContinue()) {
        Raylib::updateCamera(&camera);
        Raylib::beginDrawing();
        
        framesCounter++;
        if (framesCounter >= (180)) {
            framesCounter = 0;
            back++;
            if (back > 4) back = 0;
            scene->setBackground("../Sprite/wallpapers/game" + std::to_string(back) + ".png");   
        }
        scene->Display(win, &camera);
        scene->playMusic();
        Raylib::beginMode3D(camera);
        drawMap(groundNorm, wallNorm, wallCass, (*map), mapPosition);
        Raylib::endMode3D();

        scene->getEntity(playersNames[numPlayer])->draw();
        scene->getEntity("playerName")->draw();
        scene->getEntity("Bomb")->draw();

        Raylib::endDrawing();
    }  
}

std::shared_ptr<Engine::Scene> createSoloGameScene(Raylib::Window *win)
{
    std::shared_ptr<Engine::Scene> soloGameScene(new Engine::Scene("soloGame"));
    
    soloGameScene->setBackground("../Sprite/wallpapers/game1.png");
    soloGameScene->setLoop(&soloGameLoop, win);
    soloGameScene->setMusicToplay("BattleMusic");
    addsoloGameButton(soloGameScene.get(), win);
    createSoloPlayer(soloGameScene.get(), win);
    return soloGameScene;
}

void createSoloPlayer(Engine::Scene *scene, Raylib::Window *win)
{
    std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
    std::vector<std::string> filepath = {"../Sprite/player/white_skin/antenne_rose_t_shirt_violet.png", "../Sprite/player/white_skin/antenne_noire_t_shirt_cyan.png", "../Sprite/player/white_skin/antenne_rose_t_shirt_cyan.png",
    "../Sprite/player/white_skin/antenne_rose_t_shirt_vert.png", "../Sprite/player/white_skin/antenne_rouge_t_shirt_jaune.png", "../Sprite/player/white_skin/antenne_rouge_t_shirt_vert.png", "../Sprite/player/white_skin/antenne_noire_t_shirt_bleu.png",
    "../Sprite/player/brown_skin/antenne_noire_t_shirt_orange.png", "../Sprite/player/brown_skin/antenne_noire_t_shirt_violet.png", "../Sprite/player/brown_skin/antenne_rose_t_shirt_cyan.png",
    "../Sprite/player/brown_skin/antenne_rose_t_shirt_violet.png", "../Sprite/player/brown_skin/antenne_rouge_t_shirt_rougeAuVin.png", "../Sprite/player/brown_skin/antenne_rouge_t_shirt_vert.png"};
    std::ifstream file("player.txt");
    std::string line;
    int numPlayer = 0;
    if(file) {
        getline(file, line);
        numPlayer = atoi(line.c_str());
    }
    static int ischange = -1;

    if (ischange == numPlayer)
        return;
    std::shared_ptr<Raylib::Texture> texture(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> player = scene->createPlayer(playersNames[numPlayer]);

    texture->loadTexture(filepath[numPlayer]);
    scene->setEntityPosition(player, 0, 0, 0);
    scene->setEntityRenderModel(player, texture, "../Sprite/player/player.iqm", Vector3{0, 10, 0}, Vector3{0.7, 0.7, 0.7}, 135, WHITE);
    scene->setEntityRenderModelAnimation(player, "../Sprite/player/player.iqm", 3);
    scene->setEntityJoystick(player, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN);
    scene->setEntityHealthPosition(player, 170, 50);
    ischange = numPlayer;

    std::shared_ptr<Engine::Entity> entity = scene->createWord("playerName");
    scene->setEntityPosition(entity, 5, 55, 0);
    scene->setEntityWrite(entity, "../Fonts/bomberman.TTF", playersNames[numPlayer], WHITE, 25);

    std::shared_ptr<Raylib::Texture> textureb(new Raylib::Texture());
    std::shared_ptr<Engine::Entity> bomb = scene->createGrenade("Bomb");

    textureb->loadTexture("../Sprite/bombs/bomb7.png");
    scene->setEntityPosition(bomb, 15, 0, 0);
    scene->setEntityRenderModel(bomb, textureb, "../Sprite/bombs/bomb.obj", Vector3{0, 10, 0}, Vector3{2.5, 2.5, 2.5}, 135, WHITE);
    scene->setEntityCollision(player, scene->getMapSelectedAddr(), " ");
}

void addsoloGameButton(Engine::Scene *scene, Raylib::Window *win)
{
    std::shared_ptr<Engine::SpriteButton> Close(new Engine::SpriteButton("Close", "Exit"));
    std::shared_ptr<Engine::SpriteButton> Home(new Engine::SpriteButton("Home", "main"));
    std::shared_ptr<Engine::SpriteButton> Help( new Engine::SpriteButton("Help", "Help"));
    std::shared_ptr<Engine::SpriteButton> Params( new Engine::SpriteButton("Params", "Settings"));
    std::shared_ptr<Engine::SpriteButton> Pause( new Engine::SpriteButton("Pause", "Pause"));
  
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

    Pause->addState("../Sprite/buttons/pause0.png");
    Pause->addState("../Sprite/buttons/pause1.png");
    Pause->addState("../Sprite/buttons/pause2.png");
    Pause->resize(50, 50);
    Pause->setPosition(910, 10);
    Pause->setSound("../Sounds/buttons/hover00.ogg", "../Sounds/buttons/click00.ogg");
    scene->addButton(Pause);

}