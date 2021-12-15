/*
** EPITECH PROJECT, 2020
** temp
** File description:
** Sound.cpp
*/

#include "../../include/Raylib/Raysound.hpp"

namespace Raylib {
    void Raysound::setVolume(float volume)
    {
        SetSoundVolume(_sound, volume);
    }

    Raysound::Raysound() : _filename("")
    {
    }

    void Raysound::loadSound(const char *fileName)
    {   if (_filename == "") {
            _filename = fileName;
            _sound = LoadSound(fileName);
        } else {
            UnloadSound(_sound);
            _filename = fileName;
            _sound = LoadSound(fileName);
        }
    }

    void Raysound::unloadSound(void)
    {
        if (_filename != "")
            UnloadSound(_sound);
    }

    void Raysound::playSound(void)
    {
        PlaySound(_sound);
    }

    void Raysound::stopSound(void)
    {
        StopSound(_sound);
    }
    
    void Raysound::pauseSound(void)
    {
        PauseSound(_sound);
    }

    void Raysound::resumeSound(void)
    {
        ResumeSound(_sound);
    }

    bool Raysound::isSoundPlaying(void)
    {
        return(IsSoundPlaying(_sound));
    }

    Raysound::~Raysound()
    {
        if (_filename != "")
            UnloadSound(_sound);
    }
}