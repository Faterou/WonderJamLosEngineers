#include "StatsScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "RaceScene.h"
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
        aptitudeVitesse[x].setCharacterSize(15);
        aptitudeVitesse[x].setPosition(sf::Vector2f(225 + (10* x) ,50));
    }

     for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration[u].setFont(font);
        aptitudeAcceleration[u].setColor(sf::Color::White);
        aptitudeAcceleration[u].setCharacterSize(15);
        aptitudeAcceleration[u].setPosition(sf::Vector2f(225 + (10* u) ,125));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite[x].setFont(font);
        aptitudeManiabilite[x].setColor(sf::Color::White);
        aptitudeManiabilite[x].setCharacterSize(15);
        aptitudeManiabilite[x].setPosition(sf::Vector2f(225 + (10* x) ,200));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeGenerationDePetrole[x].setFont(font);
        aptitudeGenerationDePetrole[x].setColor(sf::Color::White);
        aptitudeGenerationDePetrole[x].setCharacterSize(15);
        aptitudeGenerationDePetrole[x].setPosition(sf::Vector2f(225 + (10* x) ,275));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeSuspension[x].setFont(font);
        aptitudeSuspension[x].setColor(sf::Color::White);
        aptitudeSuspension[x].setCharacterSize(15);
        aptitudeSuspension[x].setPosition(sf::Vector2f(225 + (10* x) ,350));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeImpact[x].setFont(font);
        aptitudeImpact[x].setColor(sf::Color::White);
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


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (selectedItemIndex  > 0)
        {
            aptitude[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            aptitude[selectedItemIndex].setColor(sf::Color::Red);
            Sleep(100);
        }
        else
            cout << "wow wow wow el malade calme toi" << endl;
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
        if (selectedItemIndex < 5)
        {
            aptitude[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            aptitude[selectedItemIndex].setColor(sf::Color::Red);
            Sleep(100);
        }
        else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
     }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        Scene* next_scene = new RaceScene();
        this->changeScene(next_scene);
    }

    switch(selectedItemIndex)
    {
    case 0:

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatVitesse  > 0)
            {
                aptitudeVitesse[selectedStatVitesse].setString("");
                selectedStatVitesse--;

                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatVitesse < 19)
            {
                selectedStatVitesse++;
                aptitudeVitesse[selectedStatVitesse].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;
    case 1:
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatAcceleration  > 0)
            {
                aptitudeAcceleration[selectedStatAcceleration].setString("");
                selectedStatAcceleration--;
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatAcceleration < 19)
            {
                selectedStatAcceleration++;
                aptitudeAcceleration[selectedStatAcceleration].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 2:
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatManiabilite  > 0)
            {
                aptitudeManiabilite[selectedStatManiabilite].setString("");
                selectedStatManiabilite--;
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatManiabilite < 19)
            {
                selectedStatManiabilite++;
                aptitudeManiabilite[selectedStatManiabilite].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 3:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatGenerateurDePetrole  > 0)
            {
                aptitudeGenerationDePetrole[selectedStatGenerateurDePetrole].setString("");
                selectedStatGenerateurDePetrole--;
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatGenerateurDePetrole < 19)
            {
                selectedStatGenerateurDePetrole++;
                aptitudeGenerationDePetrole[selectedStatGenerateurDePetrole].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 4:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatSuspension  > 0)
            {
                aptitudeSuspension[selectedStatSuspension].setString("");
                selectedStatSuspension--;
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatSuspension < 19)
            {
                selectedStatSuspension++;
                aptitudeSuspension[selectedStatSuspension].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 5:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatImpact  > 0)
            {
                aptitudeImpact[selectedStatImpact].setString("");
                selectedStatImpact--;
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatImpact < 19)
            {
                selectedStatImpact++;
                aptitudeImpact[selectedStatImpact].setString("+");
                Sleep(100);

            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;


    }




}
void StatsScene::update(){}
void StatsScene::draw()
{
     window.clear();

    sf::Texture flecheQuiPointe;
    sf::Sprite fleche;

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
