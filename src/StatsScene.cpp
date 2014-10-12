#include "StatsScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "RaceScene.h"
#include "voiture.h"
#include <stdlib.h>
#include "voiture.h"
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sstream>


using namespace std;
extern Voiture* player1;
extern Voiture* player2;


StatsScene::StatsScene(GameObject winner, GameObject loser, int time_difference)
{


    view_player1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));

    horlogeDebutStats.restart();
    m_time_difference = time_difference;

    std::stringstream ss;
    ss << m_time_difference;
    string tempsRestant = ss.str();


    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "erreur" << std::endl;
    }
    //string tempsRestemps = (string)m_time_difference;
    compteur.setFont(font);
    compteur.setColor(sf::Color::White);
    compteur.setString("Temps restant : " + tempsRestant);
    compteur.setCharacterSize(20);
    compteur.setPosition(sf::Vector2f(200, 25));

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
                player1->setVitesseMax_m(--selectedStatVitesse);

                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatVitesse < 19)
            {
                player1->setVitesseMax_m(++selectedStatVitesse);
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
                player1->setAcceleration_m(--selectedStatAcceleration);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatAcceleration < 19)
            {
                player1->setAcceleration_m(++selectedStatAcceleration);
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
                player1->setManiabilite_m(--selectedStatManiabilite);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatManiabilite < 19)
            {
                cout << player1->getManiabilite_m();
                player1->setManiabilite_m(++selectedStatManiabilite);
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
                player1->setMachineEssence_m(--selectedStatGenerateurDePetrole);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatGenerateurDePetrole < 19)
            {
                player1->setMachineEssence_m(++selectedStatGenerateurDePetrole);
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
                player1->setSuspension_m(--selectedStatSuspension);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatSuspension < 19)
            {
                player1->setSuspension_m(++selectedStatSuspension);
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
                player1->setPenetrationZombie_m(--selectedStatImpact);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatImpact < 19)
            {
                player1->setPenetrationZombie_m(++selectedStatImpact);
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
          cout << player1->getPenetrationZombie_m() << endl;
}

void StatsScene::update()
{
    selectedStatVitesse = ((int)player1->getVitesseMax_m());
    selectedStatAcceleration = ((int)player1->getAcceleration_m());
    selectedStatManiabilite = ((int)player1->getManiabilite_m());
    selectedStatGenerateurDePetrole = ((int)player1->getMachineEssence_m());
    selectedStatSuspension = ((int)player1->getSuspension_m());
    selectedStatImpact = ((int)player1->getPenetrationZombie_m());


    int tempsActuel = horlogeDebutStats.getElapsedTime().asMilliseconds();
    int monTempsRestant = (m_time_difference - tempsActuel) / 1000;

    std::stringstream ss;
    ss << monTempsRestant;
    string tempsRestant = ss.str();

    compteur.setString("Temps restant : " + tempsRestant);

    if(tempsActuel >= m_time_difference)
    {
        Scene* next_scene = new RaceScene();
        this->changeScene(next_scene);
    }

    std::cout << "temps actuel: " << tempsActuel << endl;
}

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

    window.draw(compteur);


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
