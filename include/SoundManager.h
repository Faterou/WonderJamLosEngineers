#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class SoundManager
{
    public:
        SoundManager();
        virtual ~SoundManager();
        //sf::SoundBuffer* getSoundBuffer(std::string path);
        static SoundManager& getInstance();

    protected:
    private:
        static SoundManager instance;
        std::map<std::string, sf::SoundBuffer*> SoundBuffers;

};

#endif // SOUNDMANAGER_H
