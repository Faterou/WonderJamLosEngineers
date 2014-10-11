#ifndef DESTINATION_H
#define DESTINATION_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>


class Destination : public GameObject
{
    public:
        virtual void onCollision(GameObject *collidedTo);
        void setPosition(int x, int y);
        void draw();
        Destination();
        virtual ~Destination();
    protected:
    private:
        sf::Clock timer;
        bool first = true;
};

#endif // DESTINATION_H
