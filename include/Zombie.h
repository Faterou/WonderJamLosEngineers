#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <GameObject.h>

class Zombie:GameObject
{
    public:
        void draw();
        sf::Sprite getSprite();
        void setSprite(sf::Sprite);
        sf::Texture getTexture();
        void setTexture(sf::Texture);

        Zombie();
        virtual ~Zombie();
    protected:
    private:

};

#endif // ZOMBIE_H

