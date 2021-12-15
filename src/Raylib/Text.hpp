/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "myRaylib.hpp"
#include "RayRectangle.hpp"

namespace Raylib
{
    class Text
    {
    public:
        /**
         * @brief Construct a new Text object
         * 
         * @param isAuto 
         */
        Text(bool isAuto = 1);
        /**
         * @brief Destroy the Text object
         * 
         */
        ~Text();
        /**
         * @brief Set the Text object
         * 
         * @param content 
         */
        void setText(std::string content);
        /**
         * @brief Set the Font of the text
         * 
         * @param path 
         */
        void setFont(std::string path);
        /**
         * @brief Get the Font of the text
         * 
         * @return Font 
         */
        Font getFont();
        /**
         * @brief Set the Font Size
         * 
         * @param size 
         */
        void setFontSize(int size);
        /**
         * @brief Get the Font Size 
         * 
         * @return int 
         */
        int getFontSize();
        /**
         * @brief Set the Position of the text
         * 
         * @param position 
         */
        void setPosition(Vector2 position);
        /**
         * @brief Get the Position of the text
         * 
         * @return Vector2 
         */
        Vector2 getPosition();
        /**
         * @brief Set the Spacing of the text
         * 
         * @param spacing 
         */
        void setSpacing(int spacing);
        /**
         * @brief Get the Spacing of the text
         * 
         * @return int 
         */
        int getSpacing();
        /**
         * @brief Set the text Color
         * 
         * @param color 
         */
        void setColor(Color color);
        /**
         * @brief Get the Text's size
         * 
         * @return Vector2 
         */
        Vector2 getTextSize();
        /**
         * @brief Write the text in the screen
         * 
         */
        void draw();
        /**
         * @brief Draw text (using default font)
         * 
         * @param rec 
         * @param spacing 
         * @param wordWrap 
         */
        void drawTextRec(RayRectangle rec, float spacing, bool wordWrap);
    protected:
    private:
        std::string _content;
        Font _font;
        Vector2 _position;
        Color _color;
        int _size;
        bool _isAuto;
        int _spacing;
    };
};

#endif /* !TEXT_HPP_ */
