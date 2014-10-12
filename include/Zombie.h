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
        void move();
        bool getDeath();
        virtual void onCollision(GameObject*);
        Zombie();
        Zombie(std::string);
        virtual ~Zombie();
    protected:
    private:
        sf::Vector2f getHeading();
        bool death = false;

};

#endif // ZOMBIE_H

