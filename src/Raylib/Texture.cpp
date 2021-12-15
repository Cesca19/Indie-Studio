/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Texture
*/

#include "Texture.hpp"

namespace Raylib {


    Texture &Texture::operator=(const Texture &texture)
    {
        _texture = texture._texture;
        _image = texture._image;
        _filename = texture._filename;
        _isAuto = texture._isAuto;
        _rect = texture._rect;
        return *this;
    }

    Texture2D Texture::getTexture()
    {
        return _texture;
    }

    Rectangle Texture::getRectangle(void)
    {
        return (_rect);
    }

    void Texture::resize(int width, int height)
    {
        Image img = LoadImage(_filename.c_str());

        ImageResize(&img, width, height);
        UnloadTexture(_texture);
        _texture = LoadTextureFromImage(img);
        _image = GetTextureData(_texture);
        _rect = GetImageAlphaBorder(_image, 0);
    }

    void Texture::drawTextureEx(Vector2 pos, float xfactor, float yfactor, Color color)
    {
        DrawTextureEx(getTexture(), pos, xfactor, yfactor, color);
    }

    void Texture::draw(int posX, int posY, Color tint)
    {
        DrawTexture(_texture, posX, posY, tint);
    }

    void Texture::loadTextureFromImage(Image image)
    {
        _texture = LoadTextureFromImage(image);
        _image = ImageCopy(image);
        _rect = GetImageAlphaBorder(_image, 0);
    }

    void Texture::setPosition(float x, float y)
    {
        _rect.x = x;
        _rect.y = y;
    }

    void Texture::setPosition(Vector2 pos)
    {
        _rect.x = pos.y;
        _rect.y = pos.y;
    }

    void Texture::loadTexture(std::string fileName)
    {
        if (_filename == "") {
            _filename = fileName;
            _texture = LoadTexture(fileName.c_str());
            _image = GetTextureData(_texture);
            _rect = GetImageAlphaBorder(_image, 0);
        } else {
            UnloadTexture(_texture);
            UnloadImage(_image);
            _filename = fileName;
            _texture = LoadTexture(fileName.c_str());
            _image = GetTextureData(_texture);
            _rect = GetImageAlphaBorder(_image, 0);
        }
        
    }
    
    Texture::Texture(const Texture &texture)
    {
        _texture = texture._texture;
        _image = texture._image;
        _filename = texture._filename;
        _isAuto = texture._isAuto;
        _rect = texture._rect;
    }

    Texture::Texture(bool isAuto) : _filename("")
    {
        _isAuto = isAuto;
    }

    void Texture::unloadTexture(void)
    {
        if (_filename != "") {
            UnloadTexture(_texture);
            UnloadImage(_image);
        }
    }

    Texture::~Texture()
    {
        if (_filename != "" && !_isAuto) {
            UnloadTexture(_texture);
            UnloadImage(_image);
        }
    }
};