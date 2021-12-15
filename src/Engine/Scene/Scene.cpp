/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Scene
*/

#include "Scene.hpp"
#include "../Button/SpriteButton.hpp"

namespace Engine {

    void Scene::setEntityCollision(std::shared_ptr<Entity> entity, std::vector<std::string> **map, std::string goodPlaces)
    {
        _systemSetCollision->setMapInfo(entity, map, goodPlaces);
    }

    std::vector<std::string> **Scene::getMapSelectedAddr(void)
    {
        return (&_mapSelected);
    }


    std::vector<std::string> *Scene::getMapSelected(void)
    {
        return (_mapSelected);
    }

    std::vector<std::string> *Scene::getMapName(void)
    {
        return (_mapName);
    }

    std::vector<std::vector<std::string>> *Scene::getMapArr(void)
    {
        return (_mapArr);
    }

    void Scene::selectMap(std::vector<std::string> map)
    {
        *_mapSelected = map;
    }

    void Scene::launchScene(std::string name)
    {
        (*_mapScene)[name]->launchLoop() ;
    }

    void Scene::setMapLink(std::vector<std::string> *mapName, std::vector<std::vector<std::string>> *mapArr, std::vector<std::string> *mapSelected)
    {
        _mapName = mapName;
        _mapArr = mapArr;
        _mapSelected = mapSelected;
    }

    void Scene::setEntityRenderModelAnimation(std::shared_ptr<Entity> entity, std::string fileName, int animsCount)
    {
        _systemSetRenderModel->setEntityRenderModelAnimation(entity, fileName, animsCount);
    }

    void Scene::setEntityRenderModel(std::shared_ptr<Entity> entity, std::shared_ptr<Raylib::Texture> texture,
    std::string modelFile, Vector3 rotationAxis, Vector3 scale, float rotationAngle, Color color)
    {
        _systemSetRenderModel->setEntityRenderModel(entity, texture, modelFile, rotationAxis, scale, rotationAngle, color);
    }

    void Scene::setEntityWrite(std::shared_ptr<Entity> entity, std::string font, std::string content, Color color, int size)
    {
        _systemSetWrite->setEntityWrite(entity, font, content, color, size);
    }

    void Scene::setEntityWrite(std::shared_ptr<Entity> entity, std::string content)
    {
        _systemSetWrite->setEntityWrite(entity, content);
    }
    void Scene::setEntityWrite(std::shared_ptr<Entity> entity, std::string content, int size)
    {
        _systemSetWrite->setEntityWrite(entity, content, size);
    }

    void Scene::setEntityPosition(std::shared_ptr<Entity> entity, double x, double y, double z)
    {
        _systemSetPosition->setEntityPosition(entity, x, y, z);
    }

    void Scene::setEntityJoystick(std::shared_ptr<Entity> entity, int keyLeft, int keyRight, int keyUp, int keyDown)
    {
        _systemSetJoystick->setEntityJoystick(entity, keyLeft, keyRight, keyUp, keyDown);
    }

    void Scene::setEntityHealth(std::shared_ptr<Entity> entity, int current, int max)
    {
        _systemSetHealth->setEntityHealth(entity, current, max);
    }

    void Scene::setEntityHealthPosition(std::shared_ptr<Entity> entity, int x, int y)
    {
        _systemSetHealth->setEntityPosition(entity, x, y);
    }

    std::shared_ptr<Entity> Scene::createWord(std::string name)
    {
        std::shared_ptr<Entity> entity(new Word(name));

        addEntity(entity);
        return entity;
    }

    std::shared_ptr<Entity> Scene::createSprite(std::string name)
    {
        std::shared_ptr<Entity> entity(new Sprite(name));

        addEntity(entity);
        return entity;
    }

    std::shared_ptr<Entity> Scene::createPlayer(std::string name)
    {
        std::shared_ptr<Entity> entity(new Player(name));

        addEntity(entity);
        return entity;
    }

    std::shared_ptr<Entity> Scene::createGrenade(std::string name)
    {
        std::shared_ptr<Entity> entity(new Grenade(name));

        addEntity(entity);
        return entity;
    }

    std::shared_ptr<Entity> Scene::createEntity(entityType type, std::string name)
    {
        std::shared_ptr<Entity> entity(new Entity(type, name));

        addEntity(entity);
        return entity;
    }

    void Scene::resumeMusic()
    {
        *_canPlayMusic = 1;
    }

    void Scene::pauseMusic()
    {
        if (*_currentMusic != "") {
            (*_mapMusic)[*_currentMusic]->updateMusicStream();
            (*_mapMusic)[*_currentMusic]->pauseMusicStream();
        }
        *_canPlayMusic = 0;
    }

    void Scene::playMusic()
    {
        if (_music == "" || *_canPlayMusic == 0)
            return;
        if (_music != *_currentMusic) {
            if (*_currentMusic != "")
                (*_mapMusic)[*_currentMusic]->pauseMusicStream();
            *_currentMusic = _music;
            (*_mapMusic)[_music]->updateMusicStream();
            (*_mapMusic)[_music]->playMusicStream();
        } else  {
            if (*_currentMusic != "")
                (*_mapMusic)[*_currentMusic]->updateMusicStream();
            if (!(*_mapMusic)[*_currentMusic]->isMusicPlaying() && *_canPlayMusic)
                (*_mapMusic)[*_currentMusic]->resumeMusicStream();
        }
    }

    void Scene::setMusicToplay(std::string music)
    {
        _music = music;
    }

    void Scene::setMusicMap(std::unordered_map<std::string, std::shared_ptr<Raylib::MusicStream>> *mapMusic)
    {
        _mapMusic = mapMusic;
    }

    void Scene::setCurrentMusic(std::string *currentMusic, int *canPlayMusic)
    {
        _currentMusic = currentMusic;
        _canPlayMusic = canPlayMusic;
    }

    void Scene::closeWindow()
    {
        *_canContinue = 0;
    }

    void Scene::setCanContinue(int *canContinue)
    {
        _canContinue = canContinue;
    }

    int Scene::shouldContinue(void)
    {
        if (Raylib::winShouldClose())
            *_canContinue = 0;
        if (!_canContinue)
            return (0);
        return (*_canContinue);
    }

    void Scene::setMapScene(std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *mapScene)
    {
        _mapScene = mapScene;
    }

    std::string Scene::getName()
    {
        return _name;
    }

    void Scene::Display(Raylib::Window *win)
    {
        win->setBackground(_backgroundColor);
        if (_pathBackground != "")
            win->setBackground(_pathBackground);
        for (int i = 0; i < _vecButton.size(); i++) {
            _vecButton[i]->draw();
        }
        _systemRender->update();
    }

    void Scene::Display(Raylib::Window *win, Camera *camera)
    {
        win->setBackground(_backgroundColor);
        if (_pathBackground != "")
            win->setBackground(_pathBackground);
        for (int i = 0; i < _vecButton.size(); i++) {
            _vecButton[i]->draw();
        }
        _systemPlayerInput->update();
        _systemRender->update(camera);
        if (_name == "soloGame")
            _systemBombManager->update(camera);
        if (_name == "duoGame")
            _systemBombManager->update(camera, 2);
        for (int i = 0; i < _entities.size(); i++) {
            _entities[i]->unDraw();
        }
    }

    std::shared_ptr<Entity> Scene::getEntity(std::string name)
    {
        if (_mapEntities[name] != NULL)
            return _mapEntities[name];
        return NULL;
    }
    
    std::vector<std::shared_ptr<Entity>> *Scene::getAllEntities()
    {
        return &_entities;
    }

    void Scene::addEntity(std::shared_ptr<Entity> entity)
    {
        _entities.push_back(entity);
        _mapEntities[entity->getName()] = entity;
        std::dynamic_pointer_cast<CollisionManager>(_mapComponentManagers["CollisionManager"])->addEntity(entity);
        std::dynamic_pointer_cast<FollowManager>(_mapComponentManagers["FollowManager"])->addEntity(entity);
        std::dynamic_pointer_cast<HealthManager>(_mapComponentManagers["HealthManager"])->addEntity(entity);
        std::dynamic_pointer_cast<JoystickManager>(_mapComponentManagers["JoystickManager"])->addEntity(entity);
        std::dynamic_pointer_cast<MotionManager>(_mapComponentManagers["MotionManager"])->addEntity(entity);
        std::dynamic_pointer_cast<PositionManager>(_mapComponentManagers["PositionManager"])->addEntity(entity);
        std::dynamic_pointer_cast<RenderModelManager>(_mapComponentManagers["RenderModelManager"])->addEntity(entity);
        std::dynamic_pointer_cast<WriteManager>(_mapComponentManagers["WriteManager"])->addEntity(entity);
    }

    void Scene::setBackground(std::string path)
    {
        _pathBackground = path;
    }

    void Scene::setBackground(Color color)
    {
        _backgroundColor = color;
    }

    void Scene::launchLoop(void)
    {
        (*_loopPtr)(this, _win);
    }

    void Scene::setLoop(void (*ptr)(Scene*, Raylib::Window*), Raylib::Window *win)
    {
        _loopPtr = ptr;
        _win = win;
    }

    void Scene::setAllButtonMapScene(void)
    {
        for (int i = 0; i < _vecButton.size(); i++)
            _vecButton[i]->setMapScene((void *)_mapScene);
    }
    
    void Scene::addButton(std::shared_ptr<IButton> button)
    {
        _vecButton.push_back(button);
        Button[button->getName()] = button;
        button->setMapScene((void *)_mapScene);
    }

    Scene::Scene(std::string name)
    {
        _name  = name;
        _win = NULL;
        _backgroundColor = BLANK;
        _canContinue = NULL;
        _mapScene = NULL;
        _mapMusic = NULL;
        _currentMusic = NULL;
        _music = "";

        _mapComponentManagers["CollisionManager"] = std::shared_ptr<CollisionManager>(new CollisionManager);
        _mapComponentManagers["FollowManager"] = std::shared_ptr<FollowManager>(new FollowManager);
        _mapComponentManagers["HealthManager"] = std::shared_ptr<HealthManager>(new HealthManager);
        _mapComponentManagers["JoystickManager"] = std::shared_ptr<JoystickManager>(new JoystickManager);
        _mapComponentManagers["MotionManager"] = std::shared_ptr<MotionManager>(new MotionManager);
        _mapComponentManagers["RenderModelManager"] = std::shared_ptr<RenderModelManager>(new RenderModelManager);
        _mapComponentManagers["WriteManager"] = std::shared_ptr<WriteManager>(new WriteManager);
        _mapComponentManagers["PositionManager"] = std::shared_ptr<PositionManager>(new PositionManager);

        std::shared_ptr<SystemSetCollision> systemSetCollision(new SystemSetCollision(std::dynamic_pointer_cast<CollisionManager>(_mapComponentManagers["CollisionManager"])));
        _systemSetCollision = systemSetCollision;
        std::shared_ptr<SystemSetPosition> systemSetPosition(new SystemSetPosition(std::dynamic_pointer_cast<PositionManager>(_mapComponentManagers["PositionManager"])));
        _systemSetPosition = systemSetPosition;
        std::shared_ptr<SystemSetWrite> systemSetWrite(new SystemSetWrite(std::dynamic_pointer_cast<WriteManager>(_mapComponentManagers["WriteManager"])));
        _systemSetWrite = systemSetWrite;
        std::shared_ptr<SystemSetRenderModel> systemSetRenderModel(new SystemSetRenderModel(std::dynamic_pointer_cast<RenderModelManager>(_mapComponentManagers["RenderModelManager"])));
        _systemSetRenderModel = systemSetRenderModel;
        std::shared_ptr<SystemSetJoystick> systemSetJoystick(new SystemSetJoystick(std::dynamic_pointer_cast<JoystickManager>(_mapComponentManagers["JoystickManager"])));
        _systemSetJoystick = systemSetJoystick;
        std::shared_ptr<SystemSetHealth> systemSetHealth(new SystemSetHealth(std::dynamic_pointer_cast<HealthManager>(_mapComponentManagers["HealthManager"])));
        _systemSetHealth = systemSetHealth;
        std::shared_ptr<SystemRender> systemRender(new SystemRender(&_mapComponentManagers, &_entities));
        _systemRender = systemRender;
        std::shared_ptr<SystemPlayerInput> systemPlayerInput(new SystemPlayerInput(std::dynamic_pointer_cast<PositionManager>(_mapComponentManagers["PositionManager"]),
        std::dynamic_pointer_cast<JoystickManager>(_mapComponentManagers["JoystickManager"]),
        std::dynamic_pointer_cast<RenderModelManager>(_mapComponentManagers["RenderModelManager"]),
        std::dynamic_pointer_cast<CollisionManager>(_mapComponentManagers["CollisionManager"]),
        &_entities));
        _systemPlayerInput = systemPlayerInput;
        std::shared_ptr<SystemBombManager> systemBombManager(new SystemBombManager(std::dynamic_pointer_cast<PositionManager>(_mapComponentManagers["PositionManager"]),
        std::dynamic_pointer_cast<RenderModelManager>(_mapComponentManagers["RenderModelManager"]),
        std::dynamic_pointer_cast<HealthManager>(_mapComponentManagers["HealthManager"]),
        &_mapEntities, "Bomb"));
        _systemBombManager = systemBombManager;
    }

    Scene::~Scene()
    {
        _mapScene = NULL;
    }
};