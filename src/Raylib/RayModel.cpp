/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RayModel
*/

#include "../../include/Raylib/RayModel.hpp"

namespace Raylib {
    Model RayModel::getModel()
    {
        return _model;
    }

    BoundingBox RayModel::getMeshBoundingBox()
    {
        return GetMeshBoundingBox(_model.meshes[0]);
    }

    void RayModel::unloadAnimations(unsigned int count)
    {
        if (_is_anim == false)
            return;
        _is_unload = 1;
        UnloadModelAnimations(_anims, count);
    }

    void RayModel::unloadAnimation(int animIndex)
    {
        if (_is_anim == false)
            return;
        _is_unload = 1;
        UnloadModelAnimation(_anims[animIndex]);
    }

    int RayModel::getAnimsFrameCount()
    {
        if (_anims == NULL)
            return 0;
        return _anims[0].frameCount;
    }

    void RayModel::updateAnimation(int frame)
    {
        if (_is_anim == false)
            return;
        if (_anims != NULL)
            UpdateModelAnimation(_model, _anims[0], frame);
    }

    void RayModel::loadAnimations(const char *fileName, int *animsCount)
    {
        _anims = LoadModelAnimations(fileName, animsCount);
        _notMap = 1;
        _is_anim = 1;
        _animsCount = *animsCount;
    }

    void RayModel::setTexture(Raylib::Texture &texture)
    {
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture.getTexture();
    }

    void RayModel::setTexture(std::shared_ptr<Raylib::Texture> texture)
    {
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture->getTexture();
    }

    void RayModel::drawEx(Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
    {
        DrawModelEx(_model, position, rotationAxis, rotationAngle, scale, tint);
    }

    void RayModel::draw(Vector3 position, float scale, Color tint)
    {
        DrawModel(_model, position, scale, tint);
    }

    void RayModel::unloadModelKeepMeshes()
    {
        UnloadModelKeepMeshes(_model);
    }

    void RayModel::unloadModel()
    {
        UnloadModel(_model);
    }

    void RayModel::load(RayMesh mesh)
    {
        _model = LoadModelFromMesh(mesh.getMesh());
    }

    void RayModel::load(std::string fileName)
    {
        _model = LoadModel(fileName.c_str());
    }

    RayModel::RayModel(int notMap)
    {
        _anims = NULL;
        _is_anim = false;
        _is_unload = 0;
        _notMap = 0;
        _animsCount = 0;
    }

    RayModel::~RayModel()
    {
        //if (_is_unload == 0 && _notMap == 1)
        if (_is_unload == 0 && _is_anim == true) {
            for (int i = 0; i < _animsCount; i++) UnloadModelAnimation(_anims[i]);
            if (_anims != NULL)
                RL_FREE(_anims);
        }        
    }
};