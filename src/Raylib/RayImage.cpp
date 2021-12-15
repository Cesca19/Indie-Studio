/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RayImage
*/

#include "RayImage.hpp"

namespace Raylib {
    Image RayImage::getImage()
    {
        return _image;
    }

    void RayImage::unloadImage()
    {
        UnloadImage(_image);
    }

    void RayImage::loadImage(const char *fileName)
    {
        if (_filePath != "")
            unloadImage();
        _image = LoadImage(fileName);
        _filePath = fileName;
    }

    RayImage::RayImage() : _filePath("")
    {
    }

    RayImage::~RayImage()
    {
    }
};