/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Motion
*/

#ifndef MOTION_HPP_
#define MOTION_HPP_

#include "IComponent.hpp"

namespace Engine
{
    /**
     * @class Engine::Motion
     * This entity can move based on velocity and acceleration
     */
    class Motion : public IComponent
    {
    public:
        /**
         * Create a new motion Component
         * @param Vx horizontal speed
         * @param Vy vertical speed
         * @param ax horizontal acceleration
         * @param ay vertical acceleration
         */
        Motion(double Vx, double Vy, double ax, double ay);
        ~Motion();

        /**
         * @brief  set motion
         * 
         * @param Vx horizontal speed
         * @param Vy vertical speed
         * @param ax horizontal acceleration
         * @param ay vertical acceleration
         * @return ** void 
         */
        void setMotion(double Vx, double Vy, double ax, double ay);

        /**
         * @brief Get horizontal speed
         * 
         * @return ** double 
         */
        double getVx() const;

        /**
         * @brief Get vertical speed
         * 
         * @return ** double 
         */
        double getVy() const;

        /**
         * @brief Get horizontal acceleration 
         * 
         * @return ** double 
         */
        double getax() const;

        /**
         * @brief Get vertical acceleration
         * 
         * @return ** double 
         */
        double getay() const;

    protected:
    private:
        double _Vx; /*< horizontal speed */
        double _Vy; /*< vertical speed */
        double _ax; /*< horizontal acceleration */
        double _ay; /*< vertical acceleration */
    };
};

#endif /* !MOTION_HPP_ */
