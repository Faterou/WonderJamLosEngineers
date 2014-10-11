#include "RaceScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#define ZOMBIE_QUANTITY 100
#define TREE_QUANTITY 700

extern Voiture* player1;
extern Voiture* player2;

int RaceScene::round = 0;
Map map1;

RaceScene::RaceScene() : map(), chandler()
{
    Scene::getGameObjects()->push_back(player1);
    Scene::getGameObjects()->push_back(player2);
    populate();
}

RaceScene::~RaceScene()
{
    //dtor
}

void RaceScene::inputs(){
    sf::Event event;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player1->moveForward();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player1->moveBackward();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player1->rotateRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player1->rotateLeft();
    }
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyReleased)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Up:
                    cout << "KEY RELEASED!!!!" << endl;
                    break;
                default:;
            }
        }
    }
}
void RaceScene::update(){
    chandler.checkAllCollisions();
}

void RaceScene::drawObjects()
{
    for(int i=0; i<Scene::getGameObjects()->size(); i++)
    {
        if((*Scene::getGameObjects())[i] != NULL)
        {
            (*Scene::getGameObjects())[i]->draw();
        }
        else
        {
            std::cout << "Problem in RaceScene::drawObjects  -> null object" << std::endl;
        }
    }
}

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
    drawObjects();

    sf::View view_player2(sf::FloatRect(0,0,500,500)); // TODO: Modify to take into account the player position
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));
    window.setView(view_player2);
    map1.draw();
    dest.draw();
    drawObjects();

    window.display();
}

/**
    Method to populate the map with zombies
*/
void RaceScene::populate()
{
    for(int i = 0; i<TREE_QUANTITY; i++)
    {
        int x = 32 + (rand() % (246*32));
        int y = 32 + (rand() % (246*32));

        sf::Sprite s;
        s.setPosition(x,y);
        Scene::getGameObjects()->push_back(new Tree(s));
    }

    for(int i = 0; i<248; i++)
    {
        sf::Sprite s[4];
        s[0].setPosition(0,i*32);
         s[1].setPosition(248*32, i*32);
        s[2].setPosition(i*32,0);
        s[3].setPosition(i*32, 248*32);
        for(int j=0; j<4; j++)
        {
            Scene::getGameObjects()->push_back(new Tree(s[j]));
        }
    }

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
