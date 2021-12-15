/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** WRITE
*/

#ifndef WRITE_HPP_
#define WRITE_HPP_

#include "IComponent.hpp"
#include "../../Raylib/raylib.hpp"

namespace Engine {
    class Write : public IComponent
    {
        public:
            /**
             * @brief Construct a new Write object
             * 
             * @param font_name 
             * @param content 
             */
            Write(std::string font_name, std::string content);
            /**
             * @brief Destroy the Write object
             * 
             */
            ~Write();

            /**
             * @brief Set the content of the write object
             * 
             * @param content 
             * @return ** void 
             */
            void setContent(std::string content);

            /**
             * @brief Set the font of the write object
             * 
             * @param font_name 
             * @return ** void 
             */
            void setFont(std::string font_name);

            /**
             * @brief Set the Color 
             * 
             * @param color 
             */
            void setColor(Color color);

            /**
             * @brief Set the Size
             * 
             * @param size 
             */
            void setSize(int size);

            /**
             * @brief Get the content of the write object
             * 
             * @return ** std::string 
             */
            std::string getContent() const;

            /**
             * @brief Get the font of the write object
             * 
             * @return ** std::string 
             */
            std::string getFont() const;

            /**
             * @brief Get the Color
             * 
             * @return Color 
             */
            Color getColor();

            /**
             * @brief Get the Text object
             * 
             * @return std::shared_ptr<Raylib::Text> 
             */
            std::shared_ptr<Raylib::Text> getText();
            
            /**
             * @brief Get the Size of the text
             * 
             * @return int 
             */
            int getSize();
        private:
            std::shared_ptr<Raylib::Text> _text;
            std::string _font;
            std::string _content;
            Color _color;
            int _size;
    };
};

#endif /* !WRITE_HPP_ */
