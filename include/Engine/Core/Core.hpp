/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../Button/SpriteButton.hpp"

namespace Engine {
    class Core {
        public:
            /**
             * @brief Construct a new Core object
             * 
             */
            Core();

            /**
             * @brief fill all map
             * 
             */
            void fillAllMap(void);

            /**
             * @brief fill mapName with the name of all the map availavle
             * 
             */
            void initMapName(void);
            /**
             * @brief Destroy the Core object
             * 
             */
            ~Core();

            /**
             * @brief lauch the main scene
             * 
             */
            void run();
            
            /**
             * @brief add a new scene to the core 
             * 
             * @param Scene 
             */
            void addScene(std::shared_ptr<Engine::Scene> scene);

            /**
             * @brief lauch the name scene
             * 
             * @param name 
             */
            void lauchScene(std::string name);

            /**
             * @brief Get the Scene object
             * 
             * @param name 
             * @return std::shared_ptr<Engine::Scene> 
             */
            std::shared_ptr<Engine::Scene> getScene(std::string name);

            /**
             * @brief Set the Main Scene object
             * 
             * @param name 
             */
            void setMainScene(std::string name);

            /**
             * @brief Set the Window object
             * 
             * @param win 
             */
            void setWindow(Raylib::Window *win);

            /**
             * @brief add a Music to the core
             * 
             * @param music 
             */
            void addMusic(std::shared_ptr<Raylib::MusicStream> music, std::string musicName);

            /**
             * @brief Get the Music object
             * 
             * @param musicName 
             * @return std::shared_ptr<Raylib::MusicStream> 
             */
            std::shared_ptr<Raylib::MusicStream> getMusic(std::string musicName);

        private:
            Raylib::Window *_win;
            std::string _mainScene;
            std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> _mapScene;
            std::unordered_map<std::string, std::shared_ptr<Raylib::MusicStream>> _mapMusic;
            std::string _music_playing;
            std::vector<std::string> _mapName;
            std::vector<std::vector<std::string>> _mapArr;
            std::vector<std::string> _mapSelected;
            int _canContinue;
            int _canPlayMusic;
    };
};

#endif /* !CORE_HPP_ */
