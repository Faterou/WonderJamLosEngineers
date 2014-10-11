#include "Destination.h"
#include "RaceScene.h"
#include <iostream>
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;
extern Scene* current_scene;

Destination::Destination()
{
    sf::Texture texture;
    if(!texture.loadFromFile("destination.png"))
    {
        std::cout << "Cannot load file: destination.png" << std::endl;
    }
    GameObject::setTexture(texture);
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
            winner = collidedTo;
            first = false;
        }
        else
        {
            int delta_time_players = timer.getElapsedTime().asSeconds();
            first = true;
            RaceScene* s = (RaceScene*) current_scene;
            s->end_race(winner, collidedTo, delta_time_players);

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
