/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "raylib.hpp"

namespace Raylib {
    class Window {
        public:
            /**
             * @brief Construct a new Window object
             * 
             * @param width Window's width
             * @param height Window's height
             * @param name Window's name
             */
            Window(int width, int height, std::string name);
            /**
             * @brief Initialize window and OpenGL context
             * 
             */
            void Init();
            /**
             * @brief Close window and unload OpenGL context
             * 
             */
            void Close();
            /**
             * @brief 
             * 
             * @return true The window is ready
             * @return false The window is not ready
             */
            bool isWindowReady();
            /**
             * @brief Check if window is currently fullscreen
             * 
             * @return true 
             * @return false 
             */
            bool isWindowFullscreen(void);
            /**
             * @brief Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
             * 
             */
            void toggleFullscreen(void);
            /**
             * @brief Set window position on screen (only PLATFORM_DESKTOP)
             * 
             * @param x 
             * @param y 
             */
            void setWindowPosition(int x, int y);
            /**
             * @brief Set the Background of the window
             * 
             * @param color the color of the Background
             */
            void setBackground(Color color);
            /**
             * @brief Set the Background of the window with an Image
             * 
             * @param path 
             */
            void setBackground(std::string path);
            /**
             * @brief  return 1 if an event requested for closing the window is catched
             * 
             * @return true 
             * @return false 
             */
            bool shouldClose(void);
            /**
             * @brief Destroy the Window object
             * 
             */
            ~Window();
            /**
             * @brief Set the Fullscreen
             * 
             */
            void setFullscreen();
        private:
            int _width;
            int _height;
            std::string _name;
            Raylib::Texture _backgroundText;
            std::string _backgroundPath;
            int _is_screen_init;
    };
};

#endif /* !WINDOW_HPP_ */
