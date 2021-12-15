/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Word
*/

#ifndef WORD_HPP_
#define WORD_HPP_

#include "Entity.hpp"

namespace Engine {

class Word : public Entity
{
    public:
        /**
         * @brief Construct a new Word object
         * 
         * @param name 
         */
        Word(std::string name = "text");
        /**
         * @brief Destroy the Word object
         * 
         */
        ~Word();
    };
}
#endif /* !WORD_HPP_ */
