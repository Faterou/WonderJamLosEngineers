#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <GameObject.h>
#include "TextureManager.h"
#include <SFML/Audio.hpp>

class Zombie: public GameObject
{
    public:
        void draw();
        sf::Sprite* getSprite();
        void setSprite(sf::Sprite*);
        void move();
        bool getDeath();
        void drawPoints();
        GameObject* getPoints(){return &points;};
        virtual void onCollision(GameObject*);
        Zombie();
        Zombie(std::string);
        virtual ~Zombie();
    protected:
    private:
        sf::Vector2f getHeading();
        bool death = false;
        GameObject points;
        std::vector<GameObject*>::iterator pointsInVector;
};

#endif // ZOMBIE_H

