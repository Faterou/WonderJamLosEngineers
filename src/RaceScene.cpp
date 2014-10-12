#include "RaceScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>
#include <iostream>
#include <Zombie.h>
#include <ProbeObject.h>

using namespace std;

#define ZOMBIE_QUANTITY 200
#define TREE_QUANTITY 500

extern Voiture* player1;
extern Voiture* player2;

int RaceScene::round = 0;
Map map1;

RaceScene::RaceScene() : map(), chandler(), view_player1(sf::FloatRect(-250,-250,500,500)), view_player2(sf::FloatRect(0,0,500,500)), m_thread(&RaceScene::update,this)
{

    view_player1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));


    populate();
    m_thread.launch();
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
        view_player1.setCenter(player1->getSprite()->getPosition());

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player1->moveBackward();
        view_player1.setCenter(player1->getSprite()->getPosition());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player1->rotateRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player1->rotateLeft();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player2->moveForward();
        view_player2.setCenter(player2->getSprite()->getPosition());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player2->moveBackward();
        view_player2.setCenter(player2->getSprite()->getPosition());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player2->rotateRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player2->rotateLeft();
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
    while(1)
    {
        chandler.checkAllCollisions();
    }
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


    window.setView(view_player1);
    Destination dest;
    dest.setPosition(1,0);
    map1.draw();
    dest.draw();
    drawObjects();


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



    for(int i = 0; i<248/2; i++)
    {
        sf::Sprite s[4];
        s[0].setPosition(0,i*60);
        s[1].setPosition(248*32, i*60);
        s[2].setPosition(i*60,0);
        s[3].setPosition(i*60, 248*32);
        for(int j=0; j<4; j++)
        {
            Scene::getGameObjects()->push_back(new Tree(s[j]));
        }
    }

    player1->getSprite()->rotate(180);
    do
    {
        player1->getSprite()->move(rand() % (248*32),rand() % (248*32));
    } while(chandler.checkAllCollisions(player1, Scene::getGameObjects()));
    view_player1.setCenter(player1->getSprite()->getPosition());

    player2->getSprite()->rotate(180);
    do
    {
        player2->getSprite()->move(rand() % (248*32),rand() % (248*32));
    } while(chandler.checkAllCollisions(player2, Scene::getGameObjects()));
    view_player2.setCenter(player2->getSprite()->getPosition());


    Scene::getGameObjects()->push_back(player1);
    Scene::getGameObjects()->push_back(player2);

    for(int i=0; i<ZOMBIE_QUANTITY; i++)
    {
        int x;
        int y;
        int rotation = rand() % 4;
        int zombie_type = rand() % 3;
        Zombie* z;
        switch(zombie_type)
        {
            case 0:
                z = new Zombie("zombie1.png");
                break;
            case 1:
                z = new Zombie("zombie2.png");
                break;
            default:
                z = new Zombie("zombie3.png");
        }
        do
        {
            x = rand() % 248*32;
            y = rand() % 248*32;
            z->getSprite()->setPosition(x,y);
        } while(chandler.checkAllCollisions(z,Scene::getGameObjects()));
        switch(rotation)
        {
            case 0:
                z->getSprite()->setRotation(90);
                break;
            case 1:
                z->getSprite()->setRotation(180);
                break;
            case 2:
                z->getSprite()->setRotation(270);
                break;
        }
        Scene::getGameObjects()->push_back(z);
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
