/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** RenderModel
*/

#ifndef RENDERMODEL_HPP_
#define RENDERMODEL_HPP_

#include "IComponent.hpp"
#include "../../Raylib/raylib.hpp"

namespace Engine {
    class RenderModel : public IComponent
    {
    public:
        /**
         * @brief Construct a new Render Model object
         * 
         */
        RenderModel();
        
        /**
         * @brief Destroy the Render Model object
         * 
         */
        ~RenderModel();
        
        /**
         * @brief Set the RayModel object
         * 
         * @param fileName 
         */
        void setRayModel(std::string fileName);
        
        /**
         * @brief Set the Texture object
         * 
         * @param texture 
         */
        void setTexture(std::shared_ptr<Raylib::Texture> texture);
        
        /**
         * @brief Set the Animations
         * 
         * @param fileName 
         * @param animsCount 
         */
        void setAnimation(std::string fileName, int animsCount);
        
        /**
         * @brief Get the Color object
         * 
         * @return Color 
         */
        Color getColor();

        /**
         * @brief Set the Color object
         * 
         * @param color 
         */
        void setColor(Color color);

        /**
         * @brief Set the Scale object
         * 
         * @param scale 
         */
        void setScale(Vector3 scale);

        /**
         * @brief Get the Scale object
         * 
         * @return Vector3 
         */
        Vector3 getScale();

        /**
         * @brief Set the Rotation Angle object
         * 
         * @param rotationAngle 
         */
        void setRotationAngle(float rotationAngle);

        /**
         * @brief Get the Rotation Angle object
         * 
         * @return float 
         */
        float getRotationAngle();

        /**
         * @brief Set the Rotation Axis object
         * 
         * @param rotationAxis 
         */
        void setRotationAxis(Vector3 rotationAxis);
        
        /**
         * @brief Get the Rotation Axis object
         * 
         * @return Vector3 
         */
        Vector3 getRotationAxis();

        /**
         * @brief Get the Model object
         * 
         * @return std::shared_ptr<Raylib::RayModel> 
         */
        std::shared_ptr<Raylib::RayModel> getModel();

    private:
        std::shared_ptr<Raylib::RayModel> _model;
        std::shared_ptr<Raylib::Texture> _texture;
        int is_anim_set;
        Vector3 _rotationAxis;
        float _rotationAngle;
        Vector3 _scale;
        Color _color;
    };
};

#endif /* !RENDERMODEL_HPP_ */
