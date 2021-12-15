/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** MusicStream
*/

#ifndef MusicSTREAM_HPP_
#define MusicSTREAM_HPP_

#include "raylib.hpp"

namespace Raylib {
    class MusicStream {
        public:
            /**
             * @brief Construct a new Music Stream object
             * 
             */
            MusicStream();
            /**
             * @brief Destroy the Music Stream object
             * 
             */
            ~MusicStream();
            /**
             * @brief Load music stream from file
             * 
             * @param fileName 
             */
            void loadMusicStream(const char *fileName);
            /**
             * @brief Unload music stream
             * 
             */
            void unloadMusicStream();
            /**
             * @brief Start music playing
             * 
             */
            void playMusicStream();
            /**
             * @brief Check if music is playing
             * 
             * @return true 
             * @return false 
             */
            bool isMusicPlaying();
            /**
             * @brief Stop music playing
             * 
             */
            void stopMusicStream();
            /**
             * @brief Pause music playing
             * 
             */
            void pauseMusicStream();
            /**
             * @brief Resume playing paused music
             * 
             */
            void resumeMusicStream();
            /**
             * @brief Updates buffers for music streaming
             * 
             */
            void updateMusicStream(); 
        private:
            Music _music;
            std::string _fileName;
    };
};
#endif /* !MusicSTREAM_HPP_ */
