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
#include <sstream>

using namespace std;

#define ZOMBIE_QUANTITY 1000
#define TREE_QUANTITY 500

extern Voiture* player1;
extern Voiture* player2;

int RaceScene::round = 0;
Map map1;

RaceScene::RaceScene(GameObject* last_winner, GameObject* last_loser, int delta) : map(), chandler(), view_player1(sf::FloatRect(-250,-250,500,500)), view_player2(sf::FloatRect(0,0,500,500)), m_thread(&RaceScene::checkCollisions,this), terminate_thread(false),
    last_winner(last_winner), last_loser(last_loser), delta(delta)
{

    view_player1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));


    populate();
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "erreur" << std::endl;
    }
    m_thread.launch();
    clock.restart();
}

RaceScene::~RaceScene()
{
    //dtor
}

void RaceScene::inputs(){
    bool action1 = 0;
    bool action2 = 0;
    sf::Event event;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        action1 = 1;
        if(winner != player1 && (last_loser != player1 || clock.getElapsedTime().asSeconds() > delta))
        {
            player1->moveForward();
        }

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        action1 = 1;
        if(winner != player1 && (last_loser != player1 || clock.getElapsedTime().asSeconds() > delta))
        {
            player1->moveBackward();
        }
        std::cout << player1->getSprite()->getPosition().x << "," << player1->getSprite()->getPosition().y << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        action1 = 1;
        if(winner != player1 && (last_loser != player1 || clock.getElapsedTime().asSeconds() > delta))
        {
            player1->rotateRight();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        action1 = 1;
        if(winner != player1 && (last_loser != player1 || clock.getElapsedTime().asSeconds() > delta))
        {
            player1->rotateLeft();
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        action2 = 1;
        if(winner != player2 && (last_loser != player2 || clock.getElapsedTime().asSeconds() > delta))
        {
            player2->moveForward();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        action2 = 1;
        if(winner != player2 && (last_loser != player2 || clock.getElapsedTime().asSeconds() > delta))
        {
            player2->moveBackward();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        action2 = 1;
        if(winner != player2 && (last_loser != player2 || clock.getElapsedTime().asSeconds() > delta))
        {
            player2->rotateRight();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        action2 = 1;
        if(winner != player2 && (last_loser != player2 || clock.getElapsedTime().asSeconds() > delta))
        {
            player2->rotateLeft();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }

    if(!action1)
    {
        player1->idle();
    }
    if(!action2)
    {
        player2->idle();
    }
}

void RaceScene::update()
{
    for(vector<Zombie*>::iterator it = getZombies()->begin(); it < getZombies()->end(); it++)
    {
        if(!(*it)->getDeath())
            (*it)->move();
    }
    player1->move();
    player2->move();
}

void RaceScene::checkCollisions(){
    while(!terminate_thread)
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
    //player1 view
    window.clear();
    window.setView(view_player1);
    view_player1.setCenter(player1->getSprite()->getPosition().x, player1->getSprite()->getPosition().y);
    map1.draw();
    drawObjects();
    player2->draw();
    player1->draw();
    if(winner == player1)
    {
        view_player1.setCenter(3700,3700);

        sf::CircleShape circle(100);
        circle.setPosition(destination->getSprite()->getPosition().x -50, destination->getSprite()->getPosition().y -50);
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);

        sf::CircleShape circle2(100);
        circle2.setPosition(player2->getSprite()->getPosition().x - 50, player2->getSprite()->getPosition().y - 50);
        circle2.setFillColor(sf::Color::Blue);
        window.draw(circle2);
    }

    sf::Text petrol1;
    ostringstream oss;
    oss << "Pétrole: " << player1->getPetrole();
    petrol1.setFont(font);
    petrol1.setColor(sf::Color::White);
    petrol1.setString(oss.str());
    petrol1.setCharacterSize(20);
    petrol1.setPosition(sf::Vector2f(player1->getSprite()->getPosition().x - 250, player1->getSprite()->getPosition().y -250));
    window.draw(petrol1);

    if(last_loser == player1 && delta - clock.getElapsedTime().asSeconds() > 0)
    {
        sf::Text t_delta;
        ostringstream oss12;
        oss12 << "Attendez " << (int)(delta - clock.getElapsedTime().asSeconds()) << " secondes...";
        t_delta.setFont(font);
        t_delta.setColor(sf::Color::White);
        t_delta.setString(oss12.str());
        t_delta.setCharacterSize(20);
        t_delta.setPosition(sf::Vector2f(player1->getSprite()->getPosition().x - 50, player1->getSprite()->getPosition().y +200));
        window.draw(t_delta);
    }

    //player2 view
    window.setView(view_player2);
    view_player2.setCenter(player2->getSprite()->getPosition().x, player2->getSprite()->getPosition().y);
    map1.draw();
    drawObjects();
    player1->draw();
    player2->draw();
    if(winner == player2)
    {
        view_player2.setCenter(3700,3700);

        sf::CircleShape circle(100);
        circle.setPosition(destination->getSprite()->getPosition().x -50, destination->getSprite()->getPosition().y -50);
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);

        sf::CircleShape circle2(100);
        circle2.setPosition(player1->getSprite()->getPosition().x -50, player1->getSprite()->getPosition().y -50);
        circle2.setFillColor(sf::Color::Blue);
        window.draw(circle2);
    }
    sf::Text petrol2;
    ostringstream oss2;
    oss2 << "Pétrole: " << player2->getPetrole();
    petrol2.setFont(font);
    petrol2.setColor(sf::Color::White);
    petrol2.setString(oss2.str());
    petrol2.setCharacterSize(20);
    petrol2.setPosition(sf::Vector2f(player2->getSprite()->getPosition().x - 250, player2->getSprite()->getPosition().y -250));
    window.draw(petrol2);

    if(last_loser == player2 && delta - clock.getElapsedTime().asSeconds() > 0)
    {
        sf::Text t_delta;
        ostringstream oss12;
        oss12 << "Attendez " << (int)(delta - clock.getElapsedTime().asSeconds()) << " secondes...";
        t_delta.setFont(font);
        t_delta.setColor(sf::Color::White);
        t_delta.setString(oss12.str());
        t_delta.setCharacterSize(20);
        t_delta.setPosition(sf::Vector2f(player2->getSprite()->getPosition().x - 50, player2->getSprite()->getPosition().y +200));
        window.draw(t_delta);
    }

    //player1 map
    if(winner != player1)
    {
        sf::View view_player1_map(sf::FloatRect(-200,-200,8400, 8400));
        view_player1_map.setViewport(sf::FloatRect(0.4, 0, 0.1, 0.2));
        window.setView(view_player1_map);
        view_player1_map.setCenter(4000,4000);

        sf::RectangleShape rect1(sf::Vector2f(8400,8400));
        rect1.setPosition(-200,-200);
        rect1.setFillColor(sf::Color(0,0,0));
        window.draw(rect1);

        sf::RectangleShape rect11(sf::Vector2f(8000,8000));
        rect11.setPosition(0,0);
        rect11.setFillColor(sf::Color(109,189,50));
        window.draw(rect11);

        drawObjects();
        sf::CircleShape circle(200);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(player1->getSprite()->getPosition().x -50, player1->getSprite()->getPosition().y -50);
        window.draw(circle);
    }

    //player2 map
    if(winner != player1)
    {
        sf::View view_player2_map(sf::FloatRect(-200,-200,8400, 8400));
        view_player2_map.setViewport(sf::FloatRect(0.9, 0, 0.1, 0.2));
        window.setView(view_player2_map);
        view_player2_map.setCenter(4000,4000);

        sf::RectangleShape rect2(sf::Vector2f(8400,8400));
        rect2.setPosition(-200,-200);
        rect2.setFillColor(sf::Color(0,0,0));
        window.draw(rect2);

        sf::RectangleShape rect22(sf::Vector2f(8000,8000));
        rect22.setPosition(0,0);
        rect22.setFillColor(sf::Color(109,189,50));
        window.draw(rect22);

        drawObjects();
        sf::CircleShape circle2(200);
        circle2.setFillColor(sf::Color::Blue);
        circle2.setPosition(player2->getSprite()->getPosition().x -50, player2->getSprite()->getPosition().y -50);
        window.draw(circle2);
    }



    window.display();
}

struct compare_objects
{
    bool operator() (GameObject* go1, GameObject* go2) { return go1->getSprite()->getPosition().y < go2->getSprite()->getPosition().y ;}
};

void RaceScene::sort_trees()
{
    compare_objects cmp;
    std::sort(Scene::getGameObjects()->begin(), Scene::getGameObjects()->end(), cmp);
}

/**
    Method to populate the map with zombies
*/
void RaceScene::populate()
{
    for(int i = 0; i<TREE_QUANTITY; i++)
    {
        int x = 32 + (rand() % (240*32));
        int y = 32 + (rand() % (240*32));

        sf::Sprite s;
        s.setPosition(x,y);
        Scene::getGameObjects()->push_back(new Tree(s));
    }



    for(int i = 0; i<265/2; i++)
    {
        sf::Sprite s[4];
        s[0].setPosition(0,i*60);
        s[1].setPosition(247*32, i*60);
        s[2].setPosition(i*60,0);
        s[3].setPosition(i*60, 247*32);
        for(int j=0; j<4; j++)
        {
            Scene::getGameObjects()->push_back(new Tree(s[j]));
        }
    }

    sort_trees();

    player1->getSprite()->rotate(180);
    do
    {
        player1->getSprite()->setPosition(100 + rand() % (240*32),100 + rand() % (240*32));
    } while(chandler.checkAllCollisions(player1, Scene::getGameObjects()));
    view_player1.setCenter(player1->getSprite()->getPosition());

    player2->getSprite()->rotate(180);
    do
    {
        player2->getSprite()->setPosition(100 + rand() % (240*32),100 + rand() % (240*32));
    } while(chandler.checkAllCollisions(player2, Scene::getGameObjects()));
    view_player2.setCenter(player2->getSprite()->getPosition());


    Scene::getGameObjects()->push_back(player1);
    Scene::getGameObjects()->push_back(player2);


    Destination* dest = new Destination();
    do
    {
        dest->getSprite()->setPosition(100 + rand() % (240*32),100 + rand() % (240*32));
    } while(chandler.checkAllCollisions(player2, Scene::getGameObjects()));
    getGameObjects()->push_back(dest);
    destination = dest;
    std::cout << dest->getSprite()->getPosition().x << "," << dest->getSprite()->getPosition().y << std::endl;


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
            x = rand() % 240*32;
            y = rand() % 240*32;
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

    for(vector<GameObject*>::iterator it = getGameObjects()->begin(); it < getGameObjects()->end(); it++)
    {
        if((*it)->getType() == GameObject::ZOMBIE)
        {
            getZombies()->push_back((Zombie*)*it);
        }
    }
}

void RaceScene::end_race(GameObject* winner, GameObject* loser, int time_difference)
{
    player1->set_vitesse_courante(0);
    player2->set_vitesse_courante(0);
    if(false && round < MAX_ROUND)
    {
        terminate_thread = true;
        round++;
        changeScene(new StatsScene(winner, loser, time_difference));
    }
    else
    {
        changeScene(new EndScene(winner, loser, time_difference));
    }
}

void RaceScene::first_player_finished(GameObject* first_player)
{
    if(first_player == player1)
    {
        view_player1.zoom(20);
        winner = player1;
    }
    else
    {
        view_player2.zoom(20);
        winner = player2;
    }
}
