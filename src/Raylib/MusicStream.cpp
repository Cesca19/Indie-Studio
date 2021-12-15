/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MusicStream
*/

#include "../../include/Raylib/MusicStream.hpp"

namespace Raylib {
    void MusicStream::stopMusicStream()
    {
        StopMusicStream(_music);
    }

    void MusicStream::updateMusicStream()
    {
        UpdateMusicStream(_music);
    }

    void MusicStream::resumeMusicStream()
    {
        ResumeMusicStream(_music);
    }

    void MusicStream::pauseMusicStream()
    {
        PauseMusicStream(_music);
    }

    void MusicStream::playMusicStream()
    {
        PlayMusicStream(_music);
    }

    bool MusicStream::isMusicPlaying()
    {
        return IsMusicStreamPlaying(_music);
    }

    void MusicStream::unloadMusicStream()
    {
        if (_fileName != "")
            UnloadMusicStream(_music);
    }

    void MusicStream::loadMusicStream(const char *fileName)
    {
        _music = LoadMusicStream(fileName);
        _fileName = fileName;
    }

    MusicStream::MusicStream()
    {
        _fileName = "";
    }

    MusicStream::~MusicStream()
    {
    }
};