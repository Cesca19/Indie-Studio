/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Word
*/

#include "Word.hpp"

namespace Engine {
    Word::Word(std::string name) : Entity(WORD, name)
    {
        _name = name;
    }

    Word::~Word()
    {
    }
};