/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** TextButton
*/

#ifndef TEXTBUTTON_HPP_
#define TEXTBUTTON_HPP_

#include "IButton.hpp"
//#include "../../Raylib/raylib.hpp"
#include "../Scene/Scene.hpp"

namespace Engine
{
    class TextButton : public IButton {
    public:
        /**
         * @brief Construct a new Text Button object
         * 
         * @param width 
         * @param height 
         */
        TextButton(std::string name, std::string target = "");
        /**
         * @brief Destroy the Text Button object
         * 
         */
        ~TextButton();
        /**
         * @brief Set the button position
         * 
         * @param position 
         */
        void setPosition(Vector2 position);
        /**
         * @brief Get the button position
         * 
         * @return Vector2 
         */
        Vector2 getPosition() const;
        /**
         * @brief Set the Text Size 
         * 
         * @param size 
         */
        void setTextSize(int size);
        /**
         * @brief Set the Text's font
         * 
         * @param font 
         */
        void setTextFont(std::string font);
        /**
         * @brief Get the Text Size
         * 
         * @return int 
         */
        int getTextSize() const;
        /**
         * @brief Set the Bounding box of the rectangle
         * 
         */
        void setRayRectangle();
    private:
        /**
         * @brief update the button rendering
         * 
         */
        void updateState();
    public:
        /**
         * @brief Check the button state
         * 
         * @return int 
         */
        int checkState();
        /**
         * @brief Set the content of the button
         * 
         * @param content 
         */
        void setText(std::string content);
        /**
         * @brief Set the Text Color
         * 
         * @param text_sample 
         * @param text_hover 
         * @param text_click 
         */
        void setTextColor(Color text_sample, Color text_hover, Color text_click);
        /**
         * @brief Set the Button color
         * 
         * @param button_sample 
         * @param button_hover 
         * @param button_click description
         */
        void setColor(Color button_sample, Color button_hover, Color button_click);
        /**
         * @brief display the button on the screen
         * 
         */
        void draw();
        /**
         * @brief Set the Sound of the button
         * 
         * @param ishover 
         * @param isclisk 
         */
        void setSound(std::string ishover, std::string isclisk);
        void setLinkScene(void *link);
        //void setLinkFunc(void (*function) ());
        std::string getName();

        /**
         * @brief Set the Map Scene object
         * 
         * @param mapScene the ptr
         */
        void setMapScene(void *mapScene);

        void setTargetScene(std::string);
    private:
        std::string _name;
        Vector2 _position;
        std::string _font;
        int _size;
        Raylib::Text _text;
        Raylib::RayRectangle _rect;
        Color _text_sample;
        Color _text_hover;
        Color _text_click;
        Color _button_sample;
        Color _button_hover;
        Color _button_click;
        Color _current_rect;
        int _current_state;
        std::string _ishover;
        std::string _isclick;
        std::shared_ptr<Raylib::Raysound> _ishoverSound;
        std::shared_ptr<Raylib::Raysound> _isClickSound;
        Engine::Scene *_scene;
        std::unordered_map<std::string, std::shared_ptr<Engine::Scene>> *_mapScene;
        //void (*_function) ();
        int _is_scene_set;
        std::string _targetScene;
        //int _is_func_set;
    };
};

#endif /* !TEXTBUTTON_HPP_ */