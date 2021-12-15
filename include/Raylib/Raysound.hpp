/*
** EPITECH PROJECT, 2020
** temp
** File description:
** Sound.hpp
*/

#ifndef RAYSOUND_HPP
#define RAYSOUND_HPP

#include "myRaylib.hpp"

namespace Raylib {
    /**
     * @brief Sound management functions
     * 
     */
    class Raysound {
        public:
        /**
         * @brief Construct a new Sound object
         * 
         */
        Raysound();
        /**
         * @brief Load sound from file into GPU memory (VRAM)
         * 
         * @param fileName 
         */
        void loadSound(const char *fileName);
        /**
         * @brief Unload sound
         * 
         * @param sound 
         */
        void unloadSound(void);
        /**
         * @brief Stop playing a sound
         * 
         * @param sound 
         */
        void playSound(void);
        /**
         * @brief Stop playing a sound
         * 
         * @param sound 
         */
        void stopSound(void);
        /**
         * @brief Pause a sound
         * 
         * @param sound 
         */
        void pauseSound(void);
        /**
         * @brief Resume a sound
         * 
         * @param sound 
         */
        void resumeSound(void); 
        /**
         * @brief Check if a sound is currently playing
         * 
         * @param sound 
         * @return true 
         * @return false 
         */
        bool isSoundPlaying(void);

        /**
         * @brief Set the Volume object
         * 
         * @param volume 
         */
        void setVolume(float volume);
        /**
         * @brief Destroy the Raysound object
         * 
         */
        ~Raysound();
    private:
        std::string _filename;
        Sound _sound;

    };

};

#endif
