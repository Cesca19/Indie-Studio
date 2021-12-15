/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetWrite
*/

#ifndef SYSTEMSETWRITE_HPP_
#define SYSTEMSETWRITE_HPP_

#include "ISystem.hpp"

namespace Engine {
    class SystemSetWrite : public ISystem
    {
    public:
        /**
         * @brief Construct a new System Set Write object
         * 
         * @param writeManager 
         */
        SystemSetWrite(std::shared_ptr<WriteManager> writeManager);
        
        /**
         * @brief Destroy the System Set Write object
         * 
         */
        ~SystemSetWrite();
        
        /**
         * @brief Set the Entity write component
         * 
         * @param entity 
         * @param font 
         * @param content 
         * @param color 
         * @param size 
         */
        void setEntityWrite(std::shared_ptr<Entity> entity, std::string font, std::string content, Color color, int size);

        /**
         * @brief Set the Entity Write object
         * 
         * @param entity 
         * @param content 
         */
        void setEntityWrite(std::shared_ptr<Entity> entity, std::string content);

        void setEntityWrite(std::shared_ptr<Entity> entity, std::string content, int size);
        
        /**
         * @brief update the system attribute each frame
         * 
         */
        void update();
    private:
        std::shared_ptr<WriteManager> _writeManager;
    };
}
#endif /* !SYSTEMSETWRITE_HPP_ */
