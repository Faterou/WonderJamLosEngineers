#include "Destination.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;

Destination::Destination()
{
    sf::Texture* texture = GameObject::getTexture();
    if(!texture->loadFromFile("destination.png"))
    {
        std::cout << "Cannot load file: destination.png" << std::endl;
    }
    this->getSprite()->setTexture(*texture);
    GameObject::setType(DESTINATION);
}

Destination::~Destination()
{
    //dtor
}

void Destination::onCollision(GameObject* collidedTo)
{
    if(collidedTo->getType() == CAR)
    {
        if(first)
        {
            timer.restart();
            first = false;
        }
        else
        {
            int delta_time_players = timer.getElapsedTime().asSeconds();
            first = true;
        }
    }
}

void Destination::setPosition(int x, int y)
{
    this->getSprite()->setPosition(x,y);
}

//void Destination::draw()
//{
//    window.draw(*GameObject::getSprite());
//}
