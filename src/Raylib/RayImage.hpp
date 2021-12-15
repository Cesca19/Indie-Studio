/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RayImage
*/

#ifndef RAYIMAGE_HPP_
#define RAYIMAGE_HPP_

#include "myRaylib.hpp"

namespace Raylib {
    class RayImage {
        public:
            /**
             * @brief Construct a new Ray Image object
             * 
             */
            RayImage();
            /**
             * @brief Destroy the Ray Image object
             * 
             */
            ~RayImage();
            /**
             * @brief Get the Image object
             * 
             * @return Image 
             */
            Image getImage();
            /**
             * @brief Load image from file into CPU memory (RAM)
             * 
             * @param fileName 
             */
            void loadImage(const char *fileName);
            /**
             * @brief Unload image from CPU memory (RAM)
             * 
             */
            void unloadImage();
        private:
            Image _image;
            std::string _filePath;
    };
};

#endif /* !RAYIMAGE_HPP_ */
