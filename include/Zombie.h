#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <GameObject.h>
#include "TextureManager.h"

class Zombie: public GameObject
{
    public:
        void draw();
        sf::Sprite* getSprite();
        void setSprite(sf::Sprite*);
        Zombie();
        Zombie(std::string);
        virtual ~Zombie();
    protected:
    private:

};

#endif // ZOMBIE_H

