#include "Zombie.h"

Zombie::Zombie()
{
    //ctor
}
Zombie::Zombie(sf::Vector2i maPosition)
{
    position = maPosition;
}

Zombie::~Zombie()
{
    //dtor
}

void Zombie::setPosition(sf::Vector2i maPosition)
{
    position = maPosition;
}

sf::Vector2i Zombie::getPosition()
{
    return position;
}

void Zombie::draw()
