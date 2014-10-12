#include "StatsScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

StatsScene::StatsScene(GameObject winner, GameObject loser, int time_difference)
{

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "erreur" << std::endl;
    }

    aptitude[0].setFont(font);
    aptitude[0].setColor(sf::Color::Red);
    aptitude[0].setString("Vitesse");
    aptitude[0].setCharacterSize(15);
    aptitude[0].setPosition(sf::Vector2f(50, 50));

    aptitude[1].setFont(font);
    aptitude[1].setColor(sf::Color::White);
    aptitude[1].setString("Acceleration");
    aptitude[1].setCharacterSize(15);
    aptitude[1].setPosition(sf::Vector2f(50, 125));

    aptitude[2].setFont(font);
    aptitude[2].setColor(sf::Color::White);
    aptitude[2].setString("Maniabilite");
    aptitude[2].setCharacterSize(15);
    aptitude[2].setPosition(sf::Vector2f(50, 200));

    aptitude[3].setFont(font);
    aptitude[3].setColor(sf::Color::White);
    aptitude[3].setString("Generation de petrole");
    aptitude[3].setCharacterSize(15);
    aptitude[3].setPosition(sf::Vector2f(50, 275));

    aptitude[4].setFont(font);
    aptitude[4].setColor(sf::Color::White);
    aptitude[4].setString("Suspension");
    aptitude[4].setCharacterSize(15);
    aptitude[4].setPosition(sf::Vector2f(50, 350));

    aptitude[5].setFont(font);
    aptitude[5].setColor(sf::Color::White);
    aptitude[5].setString("Impact");
    aptitude[5].setCharacterSize(15);
    aptitude[5].setPosition(sf::Vector2f(50, 425));



    for(int x(0); x < 20; x++)
    {
        aptitudeVitesse[x].setFont(font);
        aptitudeVitesse[x].setColor(sf::Color::White);
        aptitudeVitesse[x].setString("+");
        aptitudeVitesse[x].setCharacterSize(15);
        aptitudeVitesse[x].setPosition(sf::Vector2f(225 + (10* x) ,50));
    }

     for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration[u].setFont(font);
        aptitudeAcceleration[u].setColor(sf::Color::White);
        aptitudeAcceleration[u].setString("+");
        aptitudeAcceleration[u].setCharacterSize(15);
        aptitudeAcceleration[u].setPosition(sf::Vector2f(225 + (10* u) ,125));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite[x].setFont(font);
        aptitudeManiabilite[x].setColor(sf::Color::White);
        aptitudeManiabilite[x].setString("+");
        aptitudeManiabilite[x].setCharacterSize(15);
        aptitudeManiabilite[x].setPosition(sf::Vector2f(225 + (10* x) ,200));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeGenerationDePetrole[x].setFont(font);
        aptitudeGenerationDePetrole[x].setColor(sf::Color::White);
        aptitudeGenerationDePetrole[x].setString("+");
        aptitudeGenerationDePetrole[x].setCharacterSize(15);
        aptitudeGenerationDePetrole[x].setPosition(sf::Vector2f(225 + (10* x) ,275));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeSuspension[x].setFont(font);
        aptitudeSuspension[x].setColor(sf::Color::White);
        aptitudeSuspension[x].setString("+");
        aptitudeSuspension[x].setCharacterSize(15);
        aptitudeSuspension[x].setPosition(sf::Vector2f(225 + (10* x) ,350));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeImpact[x].setFont(font);
        aptitudeImpact[x].setColor(sf::Color::White);
        aptitudeImpact[x].setString("+");
        aptitudeImpact[x].setCharacterSize(15);
        aptitudeImpact[x].setPosition(sf::Vector2f(225 + (10* x) ,425));
    }
}

StatsScene::~StatsScene()
{
    //dtor
}
void StatsScene::afficherStats()
{

}

void StatsScene::inputs()
{
    sf::Event event1;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "allo" << std::endl;
        if (selectedItemIndex  > 0)
        {
        aptitude[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        aptitude[selectedItemIndex].setColor(sf::Color::Red);
        Sleep(100);
        }
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
        if (selectedItemIndex > 0)
        {
            aptitude[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            aptitude[selectedItemIndex].setColor(sf::Color::Red);
            Sleep(100);
        }
     }

}
void StatsScene::update(){}
void StatsScene::draw()
{
     window.clear();

    sf::Texture texture;
    sf::Texture flecheQuiPointe;
    sf::Sprite fleche;
    sf::Sprite sprite;

    if (!texture.loadFromFile("imageMenu.png"))
    {
        std::cout << "Ca marche pas gros mongole" << std::endl;
    }

    sprite.setTexture(texture);



    if (!flecheQuiPointe.loadFromFile("fleche.png"))
    {
        std::cout << "erreur" << std::endl;
    }

    fleche.setTexture(flecheQuiPointe);

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeVitesse[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeAcceleration[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeManiabilite[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeGenerationDePetrole[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeSuspension[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeImpact[i]));
   }


    for (int i = 0; i < 6; i++)
    {
        window.draw(aptitude[i]);
    }

    window.draw(fleche);

    window.display();

}
