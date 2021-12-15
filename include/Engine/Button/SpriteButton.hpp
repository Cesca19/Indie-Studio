/*
** EPITECH PROJECT, 2021
#include <memory>
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SpriteButton
*/

#ifndef SPRITEBUTTON_HPP_
#define SPRITEBUTTON_HPP_

#include "../../Raylib/raylib.hpp"
#include "./TextButton.hpp"

namespace Engine {
    class SpriteButton : public IButton
    {
        public:

        /**
         * @brief draw the button
         * 
         */

        void draw(void);

        /**
         * @brief Add a texture to State Array
         * 
         * @param path the path for the texture 
         */


        void addState(std::string path);

        /**
         * @brief return the current state;
         * 
         * @return int the state;
         */
        int checkState();

        /**
         * @brief update the state of the Button
         * 
         */

        void updateState(void);

        /**
         * @brief Set the Position of the button
         * 
         * @param position the new position of the button
         */

        void setPosition(Vector2 position);

        /**
         * @brief Set the Position object
         * 
         * @param x 
         * @param y 
         */

        void setPosition(float x, float y);
        /**
         * @brief Get the Position of the button
         * 
         * @return Vector2 
         */

        /**
         * @brief Get the Position of the vector
         * 
         * @return Vector2 
         */

        Vector2 getPosition() const;

        /**
         * @brief Set the Size of the button
         * 
         * @param size the size
         */

        void setSize(int size);

        /**
         * @brief Set the Size object
         * 
         * @param width 
         * @param height 
         */
        void resize(int width, int height);
        /**
         * @brief Get the Size of the button
         * 
         * @return int the size
         */

        int getSize() const;
        /**
         * @brief Construct a new Sprite Button object
         * 
         */
        SpriteButton(std::string name, std::string target="");
        /**
         * @brief Destroy the Sprite Button object
         * 
         */
        ~SpriteButton();
        /**
         * @brief Set the Sound of the button
         * 
         * @param ishover 
         * @param isclisk 
         */
        void setSound(std::string ishover, std::string isclisk);
        void setLinkScene(void *link);
        //void setLinkFunc(void (Raylib::Window:: *function) ());
        std::string getName();

        /**
         * @brief Set the Map Scene object
         * 
         * @param mapScene 
         */
        void setMapScene(void *mapScene);
        void setTargetScene(std::string);
        private:
            std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *_mapScene;
            std::string _name;
            std::vector<std::shared_ptr<Raylib::Texture>> _stateArray;
            Raylib::Texture *_currentState;
            int _stateSize;
            int _sizeButton;
            int _width;
            int _height;
            Vector2 _pos;
            int _state;
            std::string _ishover;
            std::string _isclick;
            std::shared_ptr<Raylib::Raysound> _ishoverSound;
            std::shared_ptr<Raylib::Raysound> _isClickSound;
            Engine::Scene *_scene;
            std::string _targetScene;
            //void (Raylib::Window:: *_function) ();
            int _is_scene_set;
            //int _is_func_set;
    };

};
#endif /* !SPRITEBUTTON_HPP_ */
