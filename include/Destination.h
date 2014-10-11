#ifndef DESTINATION_H
#define DESTINATION_H

#include "GameObject.h"
#include <SFML/System.hpp>


class Destination : public GameObject
{
    public:
        virtual void onCollision(GameObject *collidedTo);
        Destination();
        virtual ~Destination();
    protected:
    private:
        sf::Clock timer;
        bool first = true;
};

#endif // DESTINATION_H
