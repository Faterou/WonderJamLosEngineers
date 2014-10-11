#include "Destination.h"

Destination::Destination()
{
    //ctor
}

Destination::~Destination()
{
    //dtor
}

void Destination::onCollision(GameObject* collidedTo)
{
    if(collidedTo->type == CAR)
    {
        if(first)
        {
            timer.restart();
            first = false;
        }
        else
        {
            int delta_time_players = timer.getElapsedTime().asSeconds();
            // TODO: do something
        }
    }
}
