#include "SoundManager.h"
#include <stdexcept>
#include <string>

SoundManager SoundManager::instance;

SoundManager::SoundManager()
{
    //ctor
}

SoundManager::~SoundManager()
{
    //dtor
}
/*
sf::SoundBuffer* SoundManager::getSoundBuffer(std::string path)
{
    try
    {
        sf::SoundBuffer* backgroundBuffer = SoundBuffers.at(path);
        return backgroundBuffer;
    }

    catch(const std::out_of_range& e)
    {
        std::cout << "etape 1 \n";
        sf::SoundBuffer backgroundBuffer;

        if (!backgroundBuffer.loadFromFile(path))
        {
           std::cout << "impossible de loader la musique background \n";
        }
std::cout << "etape 5 \n";
        std::cout << "étape 6 \n";

       // SoundBuffers[path] = backgroundBuffer;

        return sound;
    }

}
*/
SoundManager& SoundManager::getInstance()
{
    return instance;
}
