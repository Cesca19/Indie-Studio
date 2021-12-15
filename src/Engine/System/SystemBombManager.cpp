/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemBombManager
*/

#include "../../../include/Engine/System/SystemBombManager.hpp"

namespace Engine {
    void SystemBombManager::drawBomb(Camera *camera, float x, float y, float z)
    {
        Raylib::beginMode3D(*camera);
        _model->drawEx(Vector3{x, y, z},
        {0, 10, 0}, 135, {1, 1, 1}, WHITE);
        Raylib::endMode3D();
    }

    void SystemBombManager::update(Camera *camera)
    {
        std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
        std::ifstream file("player.txt");
        std::string line;
        int numPlayer = 0;
        static double timer = 0;
        static float x = 0, y = 0, z = 0;

        if(file) {
            getline(file, line);
            numPlayer = atoi(line.c_str());
        }
        std::shared_ptr<Position> positionPlayer = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[numPlayer]]));
        std::shared_ptr<Health> healthPlayer = std::dynamic_pointer_cast<Health>(_healthManager->getComponent((*_entities)[playersNames[numPlayer]]));

        
        if (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Ray ray = Raylib::getMouseRay(Raylib::getMousePosition(), *camera);
            if (CheckCollisionRaySphere(ray, (Vector3){14.2, -10, -14}, 2.2)) {
                x = (float)positionPlayer->getx();
                y = (float)positionPlayer->gety();
                z = (float)positionPlayer->getz();
                if (timer == 0)
                    timer = Raylib::getTime();
            }
        }

        if (timer && Raylib::getTime() - timer < 3)
            drawBomb(camera, x, y, z);
        else if (timer && Raylib::getTime() - timer >= 3) {
            _sound->setVolume(1);
            _sound->playSound();
            if (x == (float)positionPlayer->getx() && y == (float)positionPlayer->gety()
            && z == (float)positionPlayer->getz())
                healthPlayer->setCurrentHealth(healthPlayer->getCurrentHealth() - 1);
            timer = 0;
        } else
            timer = 0;
    }

    void SystemBombManager::drawBomb(Camera *camera, float x, float y, float z, int bomb)
    {
        Raylib::beginMode3D(*camera);
        if (bomb == 0)
            _model->drawEx(Vector3{x, y, z}, {0, 10, 0}, 135, {1, 1, 1}, WHITE);
        else
            _model1->drawEx(Vector3{x, y, z}, {0, 10, 0}, 135, {1, 1, 1}, WHITE);
        Raylib::endMode3D();
    }

    void SystemBombManager::checkBomb0(Camera *camera, int player0, int player1)
    {
        std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
        static float x = 0, y = 0, z = 0;
        static double timer = 0;

        std::shared_ptr<Health> healthPlayer0 = std::dynamic_pointer_cast<Health>(_healthManager->getComponent((*_entities)[playersNames[player0]]));
        std::shared_ptr<Health> healthPlayer1 = std::dynamic_pointer_cast<Health>(_healthManager->getComponent((*_entities)[playersNames[player1]]));

        std::shared_ptr<Position> positionPlayer0 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player0]]));
        std::shared_ptr<Position> positionPlayer1 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player1]]));

        if (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Ray ray = Raylib::getMouseRay(Raylib::getMousePosition(), *camera);
            if (CheckCollisionRaySphere(ray, Vector3{14.2, -10, -14}, 2.2)) {
                x = (float)positionPlayer0->getx();
                y = (float)positionPlayer0->gety();
                z = (float)positionPlayer0->getz();
                if (timer == 0)
                    timer = Raylib::getTime();
            }
        }
        if (timer && Raylib::getTime() - timer < 3)
            drawBomb(camera, x, y, z, 0);
        else if (timer && Raylib::getTime() - timer >= 3) {
            _sound->setVolume(1);
            _sound->playSound();
            if (x == (float)positionPlayer0->getx() && y == (float)positionPlayer0->gety()
            && z == (float)positionPlayer0->getz())
                healthPlayer0->setCurrentHealth(healthPlayer0->getCurrentHealth() - 1);
            if ((positionPlayer1->getx() - x) * (positionPlayer1->getx() - x) < 1
            && (positionPlayer1->getz() - z) * (positionPlayer1->getz() - z) < 1) {
                healthPlayer1->setCurrentHealth(healthPlayer1->getCurrentHealth() - 1);
            }
            timer = 0;
        } else
            timer = 0;
    }

    void SystemBombManager::checkBomb1(Camera *camera, int player0, int player1)
    {
        std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};
        static float x = 0, y = 0, z = 0;
        static double timer = 0;

        /*BeginMode3D(*camera);
        DrawSphere(Vector3{8, 5, 12.5}, 0.8, GREEN);
        EndMode3D();*/
        std::shared_ptr<Health> healthPlayer0 = std::dynamic_pointer_cast<Health>(_healthManager->getComponent((*_entities)[playersNames[player0]]));
        std::shared_ptr<Health> healthPlayer1 = std::dynamic_pointer_cast<Health>(_healthManager->getComponent((*_entities)[playersNames[player1]]));

        std::shared_ptr<Position> positionPlayer0 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player0]]));
        std::shared_ptr<Position> positionPlayer1 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player1]]));

        if (Raylib::isMouseButtonDown(MOUSE_BUTTON_LEFT) || Raylib::isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Ray ray = Raylib::getMouseRay(Raylib::getMousePosition(), *camera);
            if (CheckCollisionRaySphere(ray, Vector3{8, 5, 12.5}, 0.8)) {
                x = (float)positionPlayer1->getx();
                y = (float)positionPlayer1->gety();
                z = (float)positionPlayer1->getz();
                if (timer == 0)
                    timer = Raylib::getTime();
            }
        }
        if (timer && Raylib::getTime() - timer < 3)
            drawBomb(camera, x, y, z, 1);
        else if (timer && Raylib::getTime() - timer >= 3) {
            _sound->setVolume(1);
            _sound->playSound();
            if ((positionPlayer0->getx() - x) * (positionPlayer0->getx() - x) < 1
            && (positionPlayer0->getz() - z) * (positionPlayer0->getz() - z) < 1)
                healthPlayer0->setCurrentHealth(healthPlayer0->getCurrentHealth() - 1);
            if ((positionPlayer1->getx() - x) * (positionPlayer1->getx() - x) < 1
            && (positionPlayer1->getz() - z) * (positionPlayer1->getz() - z) < 1) {
                healthPlayer1->setCurrentHealth(healthPlayer1->getCurrentHealth() - 1);
            }
            timer = 0;
        } else
            timer = 0;
    }

    void SystemBombManager::checkPlayer(Camera *camera, int player)
    {
        std::vector<std::string> playersNames = {"Diavollo", "Melio", "Lareey", "Daisy", "Harvey", "Niko", "McBob", "Laden", "Ryu", "Aqua", "Scarlet", "Pitch", "Enzo"};

        std::ifstream file0("player0.txt");
        std::ifstream file1("player1.txt");
        std::string line;
        int player0 = 0, player1 = 1;
 
        if (file0) {
            getline(file0, line);
            player0 = atoi(line.c_str());
        }
        if (file1) {
            getline(file1, line);
            player1 = atoi(line.c_str());
        }

        std::shared_ptr<Position> positionPlayer0 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player0]]));
        std::shared_ptr<Position> positionPlayer1 = std::dynamic_pointer_cast<Position>(_positionManager->getComponent((*_entities)[playersNames[player1]]));
        
        checkBomb0(camera, /*positionPlayer0, positionPlayer1, */player0, player1);
        checkBomb1(camera, /*positionPlayer0, positionPlayer1, */player0, player1);
    }

    void SystemBombManager::update(Camera *camera, int duo)
    {
        checkPlayer(camera, 0);   
    }

    void SystemBombManager::update()
    {
        
    }

    SystemBombManager::SystemBombManager(std::shared_ptr<PositionManager> positionManager, std::shared_ptr<RenderModelManager> renderModelManager, std::shared_ptr<HealthManager> healthManager, std::unordered_map<std::string, std::shared_ptr<Engine::Entity>> *entities, std::string bomb) : _positionManager(positionManager), _renderModelManager(renderModelManager), _healthManager(healthManager), _entities(entities), _bomb(bomb), _model(new Raylib::RayModel()), _texture(new Raylib::Texture()), _model1(new Raylib::RayModel()), _texture1(new Raylib::Texture()), _sound(new Raylib::Raysound())
    {
        _texture->loadTexture("../Sprite/bombs/bomb7.png");
        _model->load("../Sprite/bombs/bomb.obj");
        _model->setTexture(_texture);
        _texture1->loadTexture("../Sprite/bombs/bomb0.png");
        _model1->load("../Sprite/bombs/bomb.obj");
        _model1->setTexture(_texture1);
        _sound->loadSound("../Sounds/bomb/bomb_fire.ogg");
    }

    SystemBombManager::~SystemBombManager()
    {
    }
};