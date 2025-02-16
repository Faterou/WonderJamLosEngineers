#include "Destination.h"
#include "RaceScene.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TextureManager.h>

extern sf::RenderWindow window;
extern Scene* current_scene;

Destination::Destination()
{
    GameObject::setTexture(TextureManager::getInstance().getTexture("destination.png"));
    GameObject::setType(DESTINATION);
    GameObject::getSprite()->setScale(2.0,2.0);
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
            RaceScene* s = (RaceScene*) current_scene;
            s->first_player_finished(collidedTo);

        }
        else if (collidedTo != winner)
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
