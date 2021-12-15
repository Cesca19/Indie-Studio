/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RenderModel
*/

#include "../../../include/Engine/Component/RenderModel.hpp"

namespace Engine {
    Color RenderModel::getColor()
    {
        return _color;
    }

    void RenderModel::setColor(Color color)
    {
        _color = color;
    }

    float RenderModel::getRotationAngle()
    {
        return _rotationAngle;
    }

    void RenderModel::setRotationAngle(float rotationAngle)
    {
        _rotationAngle = rotationAngle;
    }

    Vector3 RenderModel::getScale()
    {
        return _scale;
    }

    void RenderModel::setScale(Vector3 scale)
    {
        _scale = scale;
    }

    Vector3 RenderModel::getRotationAxis()
    {
        return _rotationAxis;
    }

    void RenderModel::setRotationAxis(Vector3 rotationAxis)
    {
        _rotationAxis = rotationAxis;
    }

    std::shared_ptr<Raylib::RayModel> RenderModel::getModel()
    {
        return _model;
    }

    void RenderModel::setAnimation(std::string fileName, int animsCount)
    {
        _model->loadAnimations(fileName.c_str(), &animsCount);
    }

    void RenderModel::setTexture(std::shared_ptr<Raylib::Texture> texture)
    {
        _texture = texture;
        _model->setTexture(texture);
    }

    void RenderModel::setRayModel(std::string fileName)
    {
        _model->load(fileName);
    }

    RenderModel::RenderModel() : _model(new Raylib::RayModel())
    {
    }

    RenderModel::~RenderModel()
    {
    }
};