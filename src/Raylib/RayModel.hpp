/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RayModel
*/

#ifndef RAYMODEL_HPP_
#define RAYMODEL_HPP_

#include "myRaylib.hpp"
#include "RayMesh.hpp"
#include "Texture.hpp"
#include <memory>

namespace Raylib {
    class RayModel {
        public:
            /**
             * @brief Construct a new Ray Model object
             * 
             */
            RayModel(int notMap = 0);
            /**
             * @brief Destroy the Ray Model object
             * 
             */
            ~RayModel();
            /**
             * @brief Load model from files (meshes and materials)
             * 
             * @param fileName 
             */
            void load(std::string fileName);
            /**
             * @brief Load model from generated mesh (default material)
             * 
             * @param mesh 
             */
            void load(RayMesh mesh);
            /**
             * @brief Unload model (including meshes) from memory (RAM and/or VRAM)
             * 
             */
            void unloadModel();
            /**
             * @brief Unload model (but not meshes) from memory (RAM and/or VRAM)
             * 
             */
            void unloadModelKeepMeshes();
            /**
             * @brief Draw a model with extended parameters
             * 
             * @param position Draw a model (with texture if set)
             * @param scale 
             * @param tint 
             */
            void draw(Vector3 position, float scale, Color tint);

            /**
             * @brief 
             * 
             * @param position 
             * @param rotationAxis 
             * @param rotationAngle 
             * @param scale 
             * @param tint 
             */
            void drawEx(Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);

            /**
             * @brief Set the Texture of the model
             * 
             * @param texture 
             */
            void setTexture(std::shared_ptr<Raylib::Texture> texture);

            /**
             * @brief Set the Texture object
             * 
             * @param texture 
             */
            void setTexture(Raylib::Texture &texture);

            /**
             * @brief Load model animations from file
             * 
             * @param fileName 
             * @param animsCount 
             */
            void loadAnimations(const char *fileName, int *animsCount);
            
            /**
             * @brief Update model animation pose
             * 
             * @param frame 
             */
            void updateAnimation(int frame);
            
            /**
             * @brief Unload animation data
             * 
             * @param anim 
             */
            void unloadAnimation(int animIndex);

            /**
             * @brief Unload animation array data
             * 
             * @param animations 
             * @param count 
             */
            void unloadAnimations(unsigned int count);

            /**
             * @brief Get the Anims Frame Count object
             * 
             */
            int getAnimsFrameCount();
            
            /**
             * @brief Get the Bounding Box object
             * 
             * @return BoundingBox 
             */
            BoundingBox getMeshBoundingBox();

            Model getModel();

        private:
            Model _model;
            Texture *_texture;
            ModelAnimation *_anims;
            int _animsCount;
            int _is_unload;
            bool _is_anim;
            int _notMap;
    };
};

#endif /* !RAYMODEL_HPP_ */
