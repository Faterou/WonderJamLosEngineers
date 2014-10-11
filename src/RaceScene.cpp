#include "RaceScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>

#define ZOMBIE_QUANTITY 100

int RaceScene::round = 0;
Map map1;
Voiture v("voitureRouge.png");

RaceScene::RaceScene()
{
    //ctor
}

RaceScene::~RaceScene()
{
    //dtor
}

void RaceScene::inputs(){}
void RaceScene::update(){}
void RaceScene::draw()
{

    window.clear();

    sf::View view_player1(sf::FloatRect(0,0,500,500)); // TODO: Modify to take into account the player position
    view_player1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    window.setView(view_player1);
    Destination dest;
    dest.setPosition(1,0);
    map1.draw();
    dest.draw();
    v.getSprite()->setPosition(0,0);
    v.draw();

    sf::View view_player2(sf::FloatRect(0,0,500,500)); // TODO: Modify to take into account the player position
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));
    window.setView(view_player2);
    map1.draw();
    dest.draw();

    window.display();
}

/**
    Method to populate the map with zombies
*/
void RaceScene::populate()
{
    for(int i=0; i<ZOMBIE_QUANTITY; i++)
    {
        // do
        // pick random (x,y)
        // while checkCollision not ok
        // Zombie z = new Zombie()
        // z.getSprite()->setPosition(x,y)
        // gameObjects.append(z);
    }
}

void RaceScene::end_race(GameObject* winner, GameObject* loser, int time_difference)
{
    if(round < MAX_ROUND)
    {
        round++;
        changeScene(new StatsScene(*winner, *loser, time_difference));
    }
    else
    {
        changeScene(new EndScene(*winner, *loser, time_difference));
    }
}
