/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "myRaylib.hpp"

namespace Raylib {
    /**
     * Rectangle type
     * 
     */
    class RayRectangle {
        public:
            /**
             * @brief Construct a new Rectangle object
             *
             * @param width Rectangle width
             * @param height Rectangle height
             */
            RayRectangle(float width, float height);
            /**
             * @brief Destroy the Ray Rectangle object
             * 
             */
            ~RayRectangle();
            /**
             * @brief Set the Position object
             * 
             * @param x x
             * @param y y
             */

            void setPosition(float x, float y);
            /**
             * @brief Set the Position object
             * 
             * @param pos the new position
             */
            void setPosition(Vector2 pos);
            /**
             * @brief 
             * 
             * @param x 
             * @param y 
             * @param width 
             * @param height 
             */
            void updRayRectangle(float x, float y, float width, float height);
            /**
             * @brief display the rectangle on the screen
             * 
             * @param color 
             */
            void draw(Color color);
            /**
             * @brief Draw rectangle with rounded edges outline
             * 
             * @param roundness 
             * @param segments 
             * @param lineThick 
             * @param color 
             */
            void draw(float roundness, int segments, Color color);
            /**
             * @brief Get the Rect object
             *
             * @return Rectangle
             */
            Rectangle getRect(void);
            /**
             * Check collison of rectangles
             *
             * @param rec rectangle
             * @return true
             * @return false
             */
            bool checkCollisionRayRecs(RayRectangle rec);
            /**
             * Chech if point collide with rect
             *
             * @param point Vector2
             * @return true
             * @return false
             */
            bool pointOnRayRectangle(Vector2 point);

        protected:
        private:
            Rectangle _rect;
            Vector2 _pos;
            int _width;
            int _height;
    };
};

#endif /* !RECTANGLE_HPP_ */
