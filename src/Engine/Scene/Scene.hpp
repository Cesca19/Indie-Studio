/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Scene
*/

#ifndef SCENE_HPP

#define SCENE_HPP

#include "../AllComponents.hpp"
#include "../AllComponentManagers.hpp"
#include "../AllEntities.hpp"
#include "../AllSystems.hpp"
#include "../Button/IButton.hpp"
#include "../../Raylib/raylib.hpp"

namespace Engine {
    /**
     * @class Engine::Scene
     * A scene is a window. It can contain buttons and entities
     */
    class Scene {
        public:
        /**
         * @brief Construct a new Scene object
         * 
         * @param name The name of the Scene.
         */
        Scene(std::string name);

        /**
         * @brief Destroy the Scene object
         * 
         */
        ~Scene();

        /**
         * @brief Set the Background of the scene with an image
         * 
         * @param path the path of the image which will be set as background
         */
        void setBackground(std::string path);

        /**
         * @brief Set the Background of the scene with a color
         * 
         * @param color the color which will be set as background
         */
        void setBackground(Color color);
        
        /**
         * @brief set the loop of the scene
         * 
         */
        void setLoop(void (*ptr)(Scene *, Raylib::Window*), Raylib::Window* win);
        
        private:
        /**
         * @brief Add an entity to the scene
         *
         * @param entity the ptr of the entity
         */
        void addEntity(std::shared_ptr<Entity> entity);
        
        public:
        /**
         * @brief launch the loop of the scene
         * 
         */
        void launchLoop(void);
        
        /**
         * @brief Display all the scene's enties
         * and its background 
         * @param win
         * @param camera
         */
        void Display(Raylib::Window *win, Camera *camera);

        /**
         * @brief Display all the scene's enties
         * and its background 
         * @param win
         */
        void Display(Raylib::Window *win);

        /**
         * @brief add a button to the scene
         * 
         * @param button 
         * @return void 
         */
        void addButton(std::shared_ptr<IButton> button);
        
        /**
         * @brief Get the Name of the Scene
         * 
         * @return std::string 
         */
        std::string getName();

        /**
         * @brief Get All Entities of the scene
         * 
         * @return std::vector<std::shared_ptr<Entity>>* 
         */
        std::vector<std::shared_ptr<Entity>> *getAllEntities();

        /**
         * @brief Get the Entity object
         * 
         * @param name 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> getEntity(std::string name);

        /**
         * @brief Set the Map Scene object
         * 
         * @param mapScene 
         */

        void setMapScene(std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *mapScene);

        /**
         * @brief Set the Music Scene object
         * 
         * @param mapMusic 
         */
        void setMusicMap(std::unordered_map<std::string, std::shared_ptr<Raylib::MusicStream>> *mapMusic);
        
        /**
         * @brief Set the Current Music
         * 
         * @param currentMusic 
         * @param canPlayMusic 
         */
        void setCurrentMusic(std::string *currentMusic, int *canPlayMusic);

        /**
         * @brief Set the Music Toplay object
         * 
         * @param musicName 
         */
        void setMusicToplay(std::string musicName);

        /**
         * 
         * @brief Set the All Button Map Scene object
         * 
         */
        void setAllButtonMapScene(void);

        /**
         * @brief Set the Can Continue addr
         * 
         * @param canContinue addr
         */
        void setCanContinue(int *canContinue);

        /**
         * @brief play the music of the scene
         * 
         */
        void playMusic();

        /**
         * @brief Resume the paused music
         * 
         */
        void resumeMusic();

        /**
         * @brief Pause the music of the scene
         * 
         */
        void pauseMusic();

        /**
         * @brief return 1 if the window can continue to be displayed otherwise 0
         * 
         * @return true 
         * @return false 
         */
        int shouldContinue(void);

        /**
         * @brief Close the window
         * 
         */
        void closeWindow();

        /**
         * @brief Create a newEntity
         * 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createEntity(entityType type, std::string name);
        
        /**
         * @brief Create a new Word Entity
         * 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createWord(std::string name);

        /**
         * @brief Create a Grenade object
         * 
         * @param name 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createGrenade(std::string name);

        /**
         * @brief Create a new Sprite Entity
         * 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createSprite(std::string name);

        /**
         * @brief Create a new Player Entity
         * 
         * @return std::shared_ptr<Entity> 
         */
        std::shared_ptr<Entity> createPlayer(std::string name);

        /**
         * @brief Set the position of a Given Entity
         * 
         * @param entity 
         * @param x 
         * @param y 
         * @param z 
         */
        void setEntityPosition(std::shared_ptr<Entity> entity, double x, double y, double z);

        /**
         * @brief Set the Write of a given Entity
         * 
         * @param entity 
         * @param font 
         * @param content 
         * @param color 
         * @param size 
         */
        void setEntityWrite(std::shared_ptr<Entity> entity, std::string font, std::string content, Color color, int size);

        /**
         * @brief Set the Entity Write object
         * 
         * @param entity 
         * @param content 
         */
        void setEntityWrite(std::shared_ptr<Entity> entity, std::string content);

        void setEntityWrite(std::shared_ptr<Entity> entity, std::string content, int size);

        /**
         * @brief Set the Entity Sprite Model
         * 
         * @param entity 
         * @param texture 
         * @param modelFile 
         * @param rotationAxis 
         * @param scale 
         * @param rotationAngle 
         * @param color 
         */
        /**
         * @brief Set the Entity Collision object
         * 
         * @param entity 
         * @param _map 
         * @param goodPlaces 
         */
        void setEntityCollision(std::shared_ptr<Entity> entity, std::vector<std::string> **_map, std::string goodPlaces);

        void setEntityRenderModel(std::shared_ptr<Entity> entity, std::shared_ptr<Raylib::Texture> texture,
        std::string modelFile, Vector3 rotationAxis, Vector3 scale, float rotationAngle, Color color);

        /**
         * @brief Set the Entity Sprite Animation animation
         * 
         * @param entity 
         * @param fileName 
         * @param animsCount 
         */
        void setEntityRenderModelAnimation(std::shared_ptr<Entity> entity, std::string fileName, int animsCount);

        /**
         * @brief Set the Entity Joystick
         * 
         * @param entity 
         * @param keyLeft 
         * @param keyRight 
         * @param keyUp 
         * @param keyDown 
         */
        void setEntityJoystick(std::shared_ptr<Entity> entity, int keyLeft, int keyRight, int keyUp, int keyDown);

        /**
         * @brief Set the Entity Health object
         * 
         * @param entity 
         * @param current 
         * @param max 
         */
        void setEntityHealth(std::shared_ptr<Entity> entity, int current, int max = 5);

        /**
         * @brief Set the Entity Health Position object
         * 
         * @param entity 
         * @param x 
         * @param y 
         */
        void setEntityHealthPosition(std::shared_ptr<Entity> entity, int x, int y);

        /**
         * @brief Set the Map Link object
         * 
         * @param _mapName 
         * @param _mapArr 
         * @param _mapSelected 
         */
        void setMapLink(std::vector<std::string> *_mapName, std::vector<std::vector<std::string>> *_mapArr, std::vector<std::string> *_mapSelected);

        /**
         * @brief launch the given scene
         * 
         * @param name 
         */
        void launchScene(std::string name);

        /**
         * @brief Get the Map Name
         * 
         * @return std::vector<std::string>* 
         */
        std::vector<std::string> *getMapName(void);

        /**
         * @brief Get the Map Arr object
         * 
         * @return std::vector<std::vector<std::string>>* 
         */
        std::vector<std::vector<std::string>> *getMapArr(void);

        /**
         * @brief select the game Map
         * 
         * @param name 
         */
        void selectMap(std::vector<std::string> name);

        /**
         * @brief Get the Map Selected
         * 
         * @return std::vector<std::string>* 
         */
        std::vector<std::string> *getMapSelected(void);

        /**
         * @brief Get the Map Selected Addr object
         * 
         * @return std::vector<std::string>** 
         */

        std::vector<std::string> **getMapSelectedAddr(void);
        private:
        std::vector<std::string> *_mapName;
        std::vector<std::vector<std::string>> *_mapArr;
        std::vector<std::string> *_mapSelected;
        std::unordered_map<std::string, std::shared_ptr<IButton>> Button;
        Raylib::Window* _win;
        void (*_loopPtr)(Scene *, Raylib::Window *win);
        std::string _name;
        Color _backgroundColor;
        std::string _pathBackground;
        std::vector<std::shared_ptr<Entity>>_entities;
        std::shared_ptr<SystemSetPosition> _systemSetPosition;
        std::shared_ptr<SystemSetCollision> _systemSetCollision;
        std::shared_ptr<SystemSetRenderModel> _systemSetRenderModel;
        std::shared_ptr<SystemSetWrite> _systemSetWrite;
        std::shared_ptr<SystemSetJoystick> _systemSetJoystick;
        std::shared_ptr<SystemSetHealth> _systemSetHealth;
        std::shared_ptr<SystemBombManager> _systemBombManager;
        std::shared_ptr<SystemRender> _systemRender;
        std::shared_ptr<SystemPlayerInput> _systemPlayerInput;
        std::vector<std::shared_ptr<IButton>> _vecButton;
        std::unordered_map<std::string, std::shared_ptr<Engine::IComponentManager>> _mapComponentManagers;
        std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *_mapScene;
        std::unordered_map<std::string, std::shared_ptr<Raylib::MusicStream>> *_mapMusic;
        std::unordered_map<std::string, std::shared_ptr<Engine::Entity>> _mapEntities;
        std::string *_currentMusic;
        int *_canContinue;
        int *_canPlayMusic;
        std::string _music;
    };
};

#endif // !SCENE_HPP