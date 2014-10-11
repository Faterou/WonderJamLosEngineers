#ifndef DESTINATION_H
#define DESTINATION_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>


class Destination : public GameObject
{
    public:
        virtual void onCollision(GameObject *collidedTo);
        void setPosition(int x, int y);
        Destination();
        virtual ~Destination();
    protected:
    private:
        sf::Clock timer;
        bool first = true;
        GameObject* winner;
};

#endif // DESTINATION_H
