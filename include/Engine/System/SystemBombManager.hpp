/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemBombManager
*/

#ifndef SYSTEMBOMBMANAGER_HPP_
#define SYSTEMBOMBMANAGER_HPP_

#include "ISystem.hpp"
#include "../../Raylib/raylib.hpp"
#include <fstream>

namespace Engine {
class SystemBombManager : public ISystem
{
    public:
        SystemBombManager(std::shared_ptr<PositionManager> positionManager, std::shared_ptr<RenderModelManager> renderModelManager, std::shared_ptr<HealthManager> healthManager, std::unordered_map<std::string, std::shared_ptr<Engine::Entity>> *_mapEntities, std::string bomb);
        ~SystemBombManager();
        void update();
        void update(Camera *camera);
        void update(Camera *camera, int duo);
        void drawBomb(Camera *camera, float x, float y, float z, int bomb);
        void drawBomb(Camera *camera, float x, float y, float z);

    private:
        void checkPlayer(Camera *camera, int player);
        void checkPlayer0(Camera *camera, int player);
        void checkBomb0(Camera *camera, int player0, int player1);
        void checkBomb1(Camera *camera, int player0, int player1);
        
        std::shared_ptr<PositionManager> _positionManager;
        std::shared_ptr<RenderModelManager> _renderModelManager;
        std::shared_ptr<HealthManager> _healthManager;
        std::unordered_map<std::string, std::shared_ptr<Engine::Entity>> *_entities;
        std::string _bomb;
        std::shared_ptr<Raylib::RayModel> _model;
        std::shared_ptr<Raylib::Texture> _texture;
        std::shared_ptr<Raylib::RayModel> _model1;
        std::shared_ptr<Raylib::Texture> _texture1;
        std::shared_ptr<Raylib::Raysound> _sound;
    };
};
#endif /* !SYSTEMBOMBMANAGER_HPP_ */
