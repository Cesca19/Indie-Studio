/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Grind
*/

#ifndef GRIND_HPP_
#define GRIND_HPP_

#include "../../Raylib/raylib.hpp"
#include <vector>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <string>
#include <fstream>

namespace Engine  {

class Grind {
    public:
        Grind();
        ~Grind();

        /**
         * @brief return the state of the rect hover selected or none
         * 
         * @param rect 
         * @return int 
         */
        int checkRectState(Raylib::RayRectangle *rect);

        /**
         * @brief Draw all Rectangles which constitue the grind
         * 
         */
        void drawRect(char c);

        /**
         * @brief Initialize rect array !!! Don't launch  before you have InitMap and set Wall
         * 
         */
        void initRect(void);
        /**
         * @brief Set the Size of the grind, the number of cases
         * 
         * @param x
         * @param y 
         */
        void setSize(int x, int y);
        /**
         * @brief   Init the array of string which constitue the map
         * 
         */
        void initMap(void);
        /**
         * @brief Get the Map object
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> getMap(void);
        /**
         * @brief assign a char to a Raylib::Texture * to distinguish all types of walls
         * 
         * @param text 
         * @param c 
         */
        void setWall(Raylib::Texture *text, char c);
        /**
         * @brief Set the start Coordonates for the grind
         * 
         * @param x 
         * @param y 
         * @param interval 
         */
        void setCoordonate(int x, int y, int interval);

        /**
         * @brief Draw the map
         * 
         */
        void drawMap(void);

    protected:
    private:
        int _x;
        int _y;
        int _startX;
        int _startY;
        int _interval;
        std::vector<std::string> _map;
        std::vector <std::vector<Raylib::RayRectangle>> _rectArr;
        std::unordered_map<char, Raylib::Texture *> _typeWall;
};

};
#endif /* !GRIND_HPP_ */
