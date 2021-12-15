/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** SystemSetWrite
*/

#include "SystemSetWrite.hpp"

namespace Engine {
    void SystemSetWrite::setEntityWrite(std::shared_ptr<Entity> entity, std::string content)
    {
        std::shared_ptr<Write> writeComponent = std::dynamic_pointer_cast<Write>(_writeManager->getComponent(entity));

        writeComponent->setContent(content);
    }

    void SystemSetWrite::setEntityWrite(std::shared_ptr<Entity> entity, std::string content, int size)
    {
        std::shared_ptr<Write> writeComponent = std::dynamic_pointer_cast<Write>(_writeManager->getComponent(entity));

        writeComponent->setContent(content);
        writeComponent->setSize(size);        
    }

    void SystemSetWrite::setEntityWrite(std::shared_ptr<Entity> entity, std::string font, std::string content, Color color, int size)
    {
        std::shared_ptr<Write> writeComponent = std::dynamic_pointer_cast<Write>(_writeManager->getComponent(entity));

        writeComponent->setContent(content);
        writeComponent->setFont(font);
        writeComponent->setColor(color);
        writeComponent->setSize(size);
    }

    void SystemSetWrite::update()
    {
    }

    SystemSetWrite::SystemSetWrite(std::shared_ptr<WriteManager> writeManager) : _writeManager(writeManager)
    {
    }

    SystemSetWrite::~SystemSetWrite()
    {
    }
};