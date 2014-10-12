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


StatsScene::StatsScene(GameObject winner, GameObject loser, int time_difference) : view_player1(sf::FloatRect(0,0,500,500)), view_player2(sf::FloatRect(0,0,500,500))
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

    aptitude1[0].setFont(font);
    aptitude1[0].setColor(sf::Color::Red);
    aptitude1[0].setString("Vitesse");
    aptitude1[0].setCharacterSize(15);
    aptitude1[0].setPosition(sf::Vector2f(50, 50));

    aptitude1[1].setFont(font);
    aptitude1[1].setColor(sf::Color::White);
    aptitude1[1].setString("Acceleration");
    aptitude1[1].setCharacterSize(15);
    aptitude1[1].setPosition(sf::Vector2f(50, 125));

    aptitude1[2].setFont(font);
    aptitude1[2].setColor(sf::Color::White);
    aptitude1[2].setString("Maniabilite");
    aptitude1[2].setCharacterSize(15);
    aptitude1[2].setPosition(sf::Vector2f(50, 200));

    aptitude1[3].setFont(font);
    aptitude1[3].setColor(sf::Color::White);
    aptitude1[3].setString("Generation de petrole");
    aptitude1[3].setCharacterSize(15);
    aptitude1[3].setPosition(sf::Vector2f(50, 275));

    aptitude1[4].setFont(font);
    aptitude1[4].setColor(sf::Color::White);
    aptitude1[4].setString("Suspension");
    aptitude1[4].setCharacterSize(15);
    aptitude1[4].setPosition(sf::Vector2f(50, 350));

    aptitude1[5].setFont(font);
    aptitude1[5].setColor(sf::Color::White);
    aptitude1[5].setString("Impact");
    aptitude1[5].setCharacterSize(15);
    aptitude1[5].setPosition(sf::Vector2f(50, 425));


    aptitude2[0].setFont(font);
    aptitude2[0].setColor(sf::Color::Red);
    aptitude2[0].setString("Vitesse");
    aptitude2[0].setCharacterSize(15);
    aptitude2[0].setPosition(sf::Vector2f(50, 50));

    aptitude2[1].setFont(font);
    aptitude2[1].setColor(sf::Color::White);
    aptitude2[1].setString("Acceleration");
    aptitude2[1].setCharacterSize(15);
    aptitude2[1].setPosition(sf::Vector2f(50, 125));

    aptitude2[2].setFont(font);
    aptitude2[2].setColor(sf::Color::White);
    aptitude2[2].setString("Maniabilite");
    aptitude2[2].setCharacterSize(15);
    aptitude2[2].setPosition(sf::Vector2f(50, 200));

    aptitude2[3].setFont(font);
    aptitude2[3].setColor(sf::Color::White);
    aptitude2[3].setString("Generation de petrole");
    aptitude2[3].setCharacterSize(15);
    aptitude2[3].setPosition(sf::Vector2f(50, 275));

    aptitude2[4].setFont(font);
    aptitude2[4].setColor(sf::Color::White);
    aptitude2[4].setString("Suspension");
    aptitude2[4].setCharacterSize(15);
    aptitude2[4].setPosition(sf::Vector2f(50, 350));

    aptitude2[5].setFont(font);
    aptitude2[5].setColor(sf::Color::White);
    aptitude2[5].setString("Impact");
    aptitude2[5].setCharacterSize(15);
    aptitude2[5].setPosition(sf::Vector2f(50, 425));

    for(int x(0); x < 20; x++)
    {
        aptitudeVitesse1[x].setFont(font);
        aptitudeVitesse1[x].setColor(sf::Color::White);
        aptitudeVitesse1[x].setCharacterSize(15);
        aptitudeVitesse1[x].setPosition(sf::Vector2f(225 + (10* x) ,50));
    }

     for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration1[u].setFont(font);
        aptitudeAcceleration1[u].setColor(sf::Color::White);
        aptitudeAcceleration1[u].setCharacterSize(15);
        aptitudeAcceleration1[u].setPosition(sf::Vector2f(225 + (10* u) ,125));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite1[x].setFont(font);
        aptitudeManiabilite1[x].setColor(sf::Color::White);
        aptitudeManiabilite1[x].setCharacterSize(15);
        aptitudeManiabilite1[x].setPosition(sf::Vector2f(225 + (10* x) ,200));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeGenerationDePetrole1[x].setFont(font);
        aptitudeGenerationDePetrole1[x].setColor(sf::Color::White);
        aptitudeGenerationDePetrole1[x].setCharacterSize(15);
        aptitudeGenerationDePetrole1[x].setPosition(sf::Vector2f(225 + (10* x) ,275));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeSuspension1[x].setFont(font);
        aptitudeSuspension1[x].setColor(sf::Color::White);
        aptitudeSuspension1[x].setCharacterSize(15);
        aptitudeSuspension1[x].setPosition(sf::Vector2f(225 + (10* x) ,350));
    }

     for(int x(0); x < 5; x++)
    {
        aptitudeImpact1[x].setFont(font);
        aptitudeImpact1[x].setColor(sf::Color::White);
        aptitudeImpact1[x].setCharacterSize(15);
        aptitudeImpact1[x].setPosition(sf::Vector2f(225 + (10* x) ,425));
    }

    for(int x(0); x < 20; x++)
    {
        aptitudeVitesse2[x].setFont(font);
        aptitudeVitesse2[x].setColor(sf::Color::White);
        aptitudeVitesse2[x].setCharacterSize(15);
        aptitudeVitesse2[x].setPosition(sf::Vector2f(225 + (10* x) ,50));
    }

     for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration2[u].setFont(font);
        aptitudeAcceleration2[u].setColor(sf::Color::White);
        aptitudeAcceleration2[u].setCharacterSize(15);
        aptitudeAcceleration2[u].setPosition(sf::Vector2f(225 + (10* u) ,125));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite2[x].setFont(font);
        aptitudeManiabilite2[x].setColor(sf::Color::White);
        aptitudeManiabilite2[x].setCharacterSize(15);
        aptitudeManiabilite2[x].setPosition(sf::Vector2f(225 + (10* x) ,200));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeGenerationDePetrole2[x].setFont(font);
        aptitudeGenerationDePetrole2[x].setColor(sf::Color::White);
        aptitudeGenerationDePetrole2[x].setCharacterSize(15);
        aptitudeGenerationDePetrole2[x].setPosition(sf::Vector2f(225 + (10* x) ,275));
    }

     for(int x(0); x < 20; x++)
    {
        aptitudeSuspension2[x].setFont(font);
        aptitudeSuspension2[x].setColor(sf::Color::White);
        aptitudeSuspension2[x].setCharacterSize(15);
        aptitudeSuspension2[x].setPosition(sf::Vector2f(225 + (10* x) ,350));
    }

     for(int x(0); x < 5; x++)
    {
        aptitudeImpact2[x].setFont(font);
        aptitudeImpact2[x].setColor(sf::Color::White);
        aptitudeImpact2[x].setCharacterSize(15);
        aptitudeImpact2[x].setPosition(sf::Vector2f(225 + (10* x) ,425));
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
        if (selectedItemIndex1  > 0)
        {
            aptitude1[selectedItemIndex1].setColor(sf::Color::White);
            selectedItemIndex1--;
            aptitude1[selectedItemIndex1].setColor(sf::Color::Red);
            Sleep(100);
        }
        else
            cout << "wow wow wow el malade calme toi" << endl;
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
        if (selectedItemIndex1 < 5)
        {
            aptitude1[selectedItemIndex1].setColor(sf::Color::White);
            selectedItemIndex1++;
            aptitude1[selectedItemIndex1].setColor(sf::Color::Red);
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

    switch(selectedItemIndex1)
    {
    case 0:

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (selectedStatVitesse1  > 0)
            {
                aptitudeVitesse1[selectedStatVitesse1].setString("");
                player1->setVitesseMax_m(--selectedStatVitesse1);

                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatVitesse1 < 19)
            {
                player1->setVitesseMax_m(++selectedStatVitesse1);
                aptitudeVitesse1[selectedStatVitesse1].setString("+");
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
            if (selectedStatAcceleration1  > 0)
            {
                aptitudeAcceleration1[selectedStatAcceleration1].setString("");
                player1->setAcceleration_m(--selectedStatAcceleration1);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatAcceleration1 < 19)
            {
                player1->setAcceleration_m(++selectedStatAcceleration1);
                aptitudeAcceleration1[selectedStatAcceleration1].setString("+");
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
            if (selectedStatManiabilite1  > 0)
            {
                aptitudeManiabilite1[selectedStatManiabilite1].setString("");
                player1->setManiabilite_m(--selectedStatManiabilite1);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatManiabilite1 < 19)
            {
                cout << player1->getManiabilite_m();
                player1->setManiabilite_m(++selectedStatManiabilite1);
                aptitudeManiabilite1[selectedStatManiabilite1].setString("+");
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
            if (selectedStatGenerateurDePetrole1  > 0)
            {
                aptitudeGenerationDePetrole1[selectedStatGenerateurDePetrole1].setString("");
                player1->setMachineEssence_m(--selectedStatGenerateurDePetrole1);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatGenerateurDePetrole1 < 19)
            {
                player1->setMachineEssence_m(++selectedStatGenerateurDePetrole1);
                aptitudeGenerationDePetrole1[selectedStatGenerateurDePetrole1].setString("+");
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
            if (selectedStatSuspension1  > 0)
            {
                aptitudeSuspension1[selectedStatSuspension1].setString("");
                player1->setSuspension_m(--selectedStatSuspension1);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatSuspension1 < 19)
            {
                player1->setSuspension_m(++selectedStatSuspension1);
                aptitudeSuspension1[selectedStatSuspension1].setString("+");
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
            if (selectedStatImpact1  > 0)
            {
                aptitudeImpact1[selectedStatImpact1].setString("");
                player1->setPenetrationZombie_m(--selectedStatImpact1);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (selectedStatImpact1 < 5)
            {
                player1->setPenetrationZombie_m(++selectedStatImpact1);
                aptitudeImpact1[selectedStatImpact1].setString("+");
                Sleep(100);

            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (selectedItemIndex2  > 0)
        {
            aptitude2[selectedItemIndex2].setColor(sf::Color::White);
            selectedItemIndex2--;
            aptitude2[selectedItemIndex2].setColor(sf::Color::Red);
            Sleep(100);
        }
        else
            cout << "wow wow wow el malade calme toi" << endl;
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
     {
        if (selectedItemIndex2 < 5)
        {
            aptitude2[selectedItemIndex2].setColor(sf::Color::White);
            selectedItemIndex2++;
            aptitude2[selectedItemIndex2].setColor(sf::Color::Red);
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

    switch(selectedItemIndex2)
    {
    case 0:

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatVitesse2  > 0)
            {
                aptitudeVitesse2[selectedStatVitesse2].setString("");
                player2->setVitesseMax_m(--selectedStatVitesse2);

                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatVitesse2 < 19)
            {
                player2->setVitesseMax_m(++selectedStatVitesse2);
                aptitudeVitesse2[selectedStatVitesse2].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;
    case 1:
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatAcceleration2  > 0)
            {
                aptitudeAcceleration2[selectedStatAcceleration2].setString("");
                player2->setAcceleration_m(--selectedStatAcceleration2);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatAcceleration2 < 19)
            {
                player2->setAcceleration_m(++selectedStatAcceleration2);
                aptitudeAcceleration2[selectedStatAcceleration2].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 2:
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatManiabilite2  > 0)
            {
                aptitudeManiabilite2[selectedStatManiabilite2].setString("");
                player2->setManiabilite_m(--selectedStatManiabilite2);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatManiabilite2 < 19)
            {
                player2->setManiabilite_m(++selectedStatManiabilite2);
                aptitudeManiabilite2[selectedStatManiabilite2].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 3:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatGenerateurDePetrole2  > 0)
            {
                aptitudeGenerationDePetrole2[selectedStatGenerateurDePetrole2].setString("");
                player2->setMachineEssence_m(--selectedStatGenerateurDePetrole2);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatGenerateurDePetrole2 < 19)
            {
                player2->setMachineEssence_m(++selectedStatGenerateurDePetrole2);
                aptitudeGenerationDePetrole2[selectedStatGenerateurDePetrole2].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 4:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatSuspension2  > 0)
            {
                aptitudeSuspension2[selectedStatSuspension2].setString("");
                player2->setSuspension_m(--selectedStatSuspension2);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatSuspension2 < 19)
            {
                player2->setSuspension_m(++selectedStatSuspension2);
                aptitudeSuspension2[selectedStatSuspension2].setString("+");
                Sleep(100);
            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;

    case 5:

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (selectedStatImpact2  > 0)
            {
                aptitudeImpact2[selectedStatImpact2].setString("");
                player2->setPenetrationZombie_m(--selectedStatImpact2);
                Sleep(100);
            }
            else
                cout << "wow wow wow el malade calme toi" << endl;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (selectedStatImpact2 < 19)
            {
                player2->setPenetrationZombie_m(++selectedStatImpact2);
                aptitudeImpact2[selectedStatImpact2].setString("+");
                Sleep(100);

            }
            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
        }

        break;
    }
          player1->miseAJourVoiture();
          player2->miseAJourVoiture();
}

void StatsScene::update()
{
    selectedStatVitesse1 = ((int)player1->getVitesseMax_m());
    selectedStatAcceleration1 = ((int)player1->getAcceleration_m());
    selectedStatManiabilite1 = ((int)player1->getManiabilite_m());
    selectedStatGenerateurDePetrole1 = ((int)player1->getMachineEssence_m());
    selectedStatSuspension1 = ((int)player1->getSuspension_m());
    selectedStatImpact1 = ((int)player1->getPenetrationZombie_m());

    selectedStatVitesse2 = ((int)player2->getVitesseMax_m());
    selectedStatAcceleration2 = ((int)player2->getAcceleration_m());
    selectedStatManiabilite2 = ((int)player2->getManiabilite_m());
    selectedStatGenerateurDePetrole2 = ((int)player2->getMachineEssence_m());
    selectedStatSuspension2 = ((int)player2->getSuspension_m());
    selectedStatImpact2 = ((int)player2->getPenetrationZombie_m());


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

    window.setView(view_player1);
    window.draw(compteur);


   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeVitesse1[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeAcceleration1[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeManiabilite1[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeGenerationDePetrole1[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeSuspension1[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeImpact1[i]));
   }


    for (int i = 0; i < 6; i++)
    {
        window.draw(aptitude1[i]);
    }

    window.setView(view_player2);
    window.draw(compteur);


   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeVitesse2[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeAcceleration2[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeManiabilite2[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeGenerationDePetrole2[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeSuspension2[i]));
   }

   for(int i(0); i < 20; i++)
   {
       window.draw((aptitudeImpact2[i]));
   }


    for (int i = 0; i < 6; i++)
    {
        window.draw(aptitude2[i]);
    }



    window.display();

}
