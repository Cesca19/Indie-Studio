/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Core
*/

#include "Core.hpp"
#include <stdlib.h>
#include <fstream>
#include <string>

namespace Engine {

    void Core::fillAllMap(void)
    {
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
    }

    void Core::initMapName(void)
    {
        std::string tmp;

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
    }

    std::shared_ptr<Raylib::MusicStream> Core::getMusic(std::string musicName)
    {
        return _mapMusic[musicName];
    }

    void Core::addMusic(std::shared_ptr<Raylib::MusicStream> music, std::string musicName)
    {
        _mapMusic[musicName] = music;
    }

    void Core::setWindow(Raylib::Window *win)
    {
        _win = win;
    }

    void Core::run()
    {
        std::shared_ptr<Engine::Scene> scene = _mapScene[_mainScene];

        if (scene)
            scene->launchLoop();
    }

    std::shared_ptr<Engine::Scene> Core::getScene(std::string name)
    {
        return (_mapScene[name]);
    }
    void Core::setMainScene(std::string name)
    {
        _mainScene = name;
    }

    void Core::addScene(std::shared_ptr<Engine::Scene> scene)
    {
        _mapScene[scene->getName()] = scene;
        scene->setMapScene(&_mapScene);
        scene->setAllButtonMapScene();
        scene->setCanContinue(&_canContinue);
        scene->setMusicMap(&_mapMusic);
        scene->setCurrentMusic(&_music_playing, &_canPlayMusic);
        scene->setMapLink(&_mapName, &_mapArr, &_mapSelected);
    }

    Core::Core()
    {
        _mainScene = "";
        _music_playing = "";
        _canContinue = 1;
        _canPlayMusic = 1;
        initMapName();
        fillAllMap();
    }

    Core::~Core()
    {
    }
};