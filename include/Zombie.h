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
        void drawPoints();
        sf::Sprite* getSpritePoints(){return points;};
        virtual void onCollision(GameObject*);
        Zombie();
        Zombie(std::string);
        virtual ~Zombie();
    protected:
    private:
        sf::Vector2f getHeading();
        bool death = false;
        sf::Sprite* points;

};

#endif // ZOMBIE_H

