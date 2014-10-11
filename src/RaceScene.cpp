#include "RaceScene.h"

#include "Destination.h"
Map map1;

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

    sf::View view_player2(sf::FloatRect(0,0,500,500)); // TODO: Modify to take into account the player position
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));
    window.setView(view_player2);
    map1.draw();
    dest.draw();

    window.display();
}
