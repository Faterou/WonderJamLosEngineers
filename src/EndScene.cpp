#include "EndScene.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <Voiture.h>
#include <MenuScene.h>

extern sf::RenderWindow window;
extern Voiture* player1;

EndScene::EndScene(GameObject* winner, GameObject* loser, int time_difference)
{
    std::ostringstream oss;
    int player_number;
    if(winner == player1) player_number = 1;
    else player_number = 2;

    oss << " Winner: " << std::endl << " player " <<player_number;
    results = oss.str();
}

EndScene::~EndScene()
{
    //dtor
}

void EndScene::inputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        changeScene(new MenuScene());
        Sleep(100);
    }
}
void EndScene::update(){}
void EndScene::draw()
{
    sf::View v(sf::FloatRect(0,0,1000,500));
    window.setView(v);
    window.clear();
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "erreur font" << std::endl;
    }
    sf::Text t;
    t.setFont(font);
    t.setColor(sf::Color::Red);
    t.setString(results);
    t.setCharacterSize(100);
    t.setPosition(sf::Vector2f(300, 120));
    window.draw(t);
    window.display();
}
