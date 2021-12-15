/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "myRaylib.hpp"

namespace Raylib {
    class Texture {
        public:
            /**
             * @brief Construct a new Texture object
             * 
             */
            Texture(bool isAuto=0);

            Texture(const Texture& texture);

            void drawTextureEx(Vector2 pos, float xfactor, float yfactor, Color color);

            Texture &operator=(const Texture &texture);

            /**
             * @brief Load texture from file into GPU memory (VRAM)
             * 
             * @param fileName 
             */
            void loadTexture(std::string filename);

            /**
             * @brief resize texture
             * 
             * @param width 
             * @param height 
             */
            void resize(int width, int height);
            /**
             * @brief Load texture from image data
             * 
             * @param image 
             */
            void loadTextureFromImage(Image image);
            /**
             * @brief Get the Texture2D object
             * @return Texture2D 
             */
            Texture2D getTexture();
            /**
             * @brief Draw a Texture2D
             * 
             * @param posX 
             * @param posY 
             * @param tint 
             */

            void draw(int posX, int posY, Color tint);
            /**
             * @brief unloadTexture contain
             * 
             */

            void unloadTexture(void);

            /**
             * @brief Get the Rect object
             * 
             * @return Rectangle 
             */

            Rectangle getRectangle(void);

            /**
             * @brief Set the Position object
             * 
             * @param x 
             * @param y 
             */

            void setPosition(float x, float y);

            /**
             * @brief Set the Position object
             * 
             * @param pos 
             */

            void setPosition(Vector2 pos);

            /**
             * @brief Destroy the Texture object
             * 
             */

            ~Texture();
        private:
            bool _isAuto;
            Texture2D _texture;
            Rectangle _rect;
            Image _image;
            std::string _filename;
    };
};
#endif /* !TEXTURE_HPP_ */
