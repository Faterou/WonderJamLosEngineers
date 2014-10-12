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


StatsScene::StatsScene(GameObject* winner, GameObject* loser, int time_difference) : view_player1(sf::FloatRect(0,0,500,500)), view_player2(sf::FloatRect(0,0,500,500)),
    winner(winner), loser(loser), delta(time_difference)
{
    if (!backgroundBuffer.loadFromFile("menuBackground.wav"))
    {
       std::cout << "impossible de loader la musique background \n";
    }

    m_sound.setBuffer(backgroundBuffer);

    m_sound.setLoop(true);

    m_sound.play();

    view_player1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
    view_player2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));



    horlogeDebutStats.restart();
    m_time_difference = 20000;

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

    pasAssezDargent[0].setFont(font);
    pasAssezDargent[0].setColor(sf::Color::Red);
    pasAssezDargent[0].setString("Manque de fond");
    pasAssezDargent[0].setCharacterSize(20);
    pasAssezDargent[0].setPosition(sf::Vector2f(250, 400));

    aptitude1[0].setFont(font);
    aptitude1[0].setColor(sf::Color::Red);
    aptitude1[0].setString("Vitesse");
    aptitude1[0].setCharacterSize(20);
    aptitude1[0].setPosition(sf::Vector2f(50, 75));

    aptitude1[1].setFont(font);
    aptitude1[1].setColor(sf::Color::White);
    aptitude1[1].setString("Acceleration");
    aptitude1[1].setCharacterSize(20);
    aptitude1[1].setPosition(sf::Vector2f(50, 115));

    aptitude1[2].setFont(font);
    aptitude1[2].setColor(sf::Color::White);
    aptitude1[2].setString("Maniabilite");
    aptitude1[2].setCharacterSize(20);
    aptitude1[2].setPosition(sf::Vector2f(50, 155));

    aptitude1[3].setFont(font);
    aptitude1[3].setColor(sf::Color::White);
    aptitude1[3].setString("Impact");
    aptitude1[3].setCharacterSize(20);
    aptitude1[3].setPosition(sf::Vector2f(50, 195));

    aptitude2[0].setFont(font);
    aptitude2[0].setColor(sf::Color::Red);
    aptitude2[0].setString("Vitesse");
    aptitude2[0].setCharacterSize(20);
    aptitude2[0].setPosition(sf::Vector2f(50, 75));

    aptitude2[1].setFont(font);
    aptitude2[1].setColor(sf::Color::White);
    aptitude2[1].setString("Acceleration");
    aptitude2[1].setCharacterSize(20);
    aptitude2[1].setPosition(sf::Vector2f(50, 115));

    aptitude2[2].setFont(font);
    aptitude2[2].setColor(sf::Color::White);
    aptitude2[2].setString("Maniabilite");
    aptitude2[2].setCharacterSize(20);
    aptitude2[2].setPosition(sf::Vector2f(50, 155));

    aptitude2[3].setFont(font);
    aptitude2[3].setColor(sf::Color::White);
    aptitude2[3].setString("Impact");
    aptitude2[3].setCharacterSize(20);
    aptitude2[3].setPosition(sf::Vector2f(50, 195));

    cash[0].setFont(font);
    cash[0].setColor(sf::Color::White);
    cash[0].setString("100$");
    cash[0].setCharacterSize(12);
    cash[0].setPosition(sf::Vector2f(0, 85));

    cash[1].setFont(font);
    cash[1].setColor(sf::Color::White);
    cash[1].setString("250$");
    cash[1].setCharacterSize(12);
    cash[1].setPosition(sf::Vector2f(0, 125));

    cash[2].setFont(font);
    cash[2].setColor(sf::Color::White);
    cash[2].setString("500$");
    cash[2].setCharacterSize(12);
    cash[2].setPosition(sf::Vector2f(0, 165));

    cash[3].setFont(font);
    cash[3].setColor(sf::Color::White);
    cash[3].setString("1500$");
    cash[3].setCharacterSize(12);
    cash[3].setPosition(sf::Vector2f(0, 195));

    description[0].setFont(font);
    description[0].setColor(sf::Color::White);
    description[0].setString("Vitesse du vehicule");
    description[0].setCharacterSize(12);
    description[0].setPosition(sf::Vector2f(450, 250));

    description[1].setFont(font);
    description[1].setColor(sf::Color::White);
    description[1].setString("Acceleration");
    description[1].setCharacterSize(12);
    description[1].setPosition(sf::Vector2f(450, 250));

    description[2].setFont(font);
    description[2].setColor(sf::Color::White);
    description[2].setString("Maniabilite");
    description[2].setCharacterSize(12);
    description[2].setPosition(sf::Vector2f(450, 250));

    description[3].setFont(font);
    description[3].setColor(sf::Color::White);
    description[3].setString("Reduction de l'impact lors de collision");
    description[3].setCharacterSize(12);
    description[3].setPosition(sf::Vector2f(450, 250));

    for(int x(0); x < 20; x++)
    {
        aptitudeVitesse1[x].setFont(font);
        aptitudeVitesse1[x].setColor(sf::Color::White);
        aptitudeVitesse1[x].setCharacterSize(15);
        aptitudeVitesse1[x].setPosition(sf::Vector2f(250 + (10* x) ,75));
    }

    for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration1[u].setFont(font);
        aptitudeAcceleration1[u].setColor(sf::Color::White);
        aptitudeAcceleration1[u].setCharacterSize(15);
        aptitudeAcceleration1[u].setPosition(sf::Vector2f(250 + (10* u) ,115));
    }

    for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite1[x].setFont(font);
        aptitudeManiabilite1[x].setColor(sf::Color::White);
        aptitudeManiabilite1[x].setCharacterSize(15);
        aptitudeManiabilite1[x].setPosition(sf::Vector2f(250 + (10* x) ,155));
    }

    for(int x(0); x < 5; x++)
    {
        aptitudeImpact1[x].setFont(font);
        aptitudeImpact1[x].setColor(sf::Color::White);
        aptitudeImpact1[x].setCharacterSize(15);
        aptitudeImpact1[x].setPosition(sf::Vector2f(250 + (10* x) ,195));
    }

    for(int x(0); x < 20; x++)
    {
        aptitudeVitesse2[x].setFont(font);
        aptitudeVitesse2[x].setColor(sf::Color::White);
        aptitudeVitesse2[x].setCharacterSize(15);
        aptitudeVitesse2[x].setPosition(sf::Vector2f(250 + (10* x) ,75));
    }

    for(int u(0); u < 20; u++)
    {
        aptitudeAcceleration2[u].setFont(font);
        aptitudeAcceleration2[u].setColor(sf::Color::White);
        aptitudeAcceleration2[u].setCharacterSize(15);
        aptitudeAcceleration2[u].setPosition(sf::Vector2f(250 + (10* u) ,115));
    }

    for(int x(0); x < 20; x++)
    {
        aptitudeManiabilite2[x].setFont(font);
        aptitudeManiabilite2[x].setColor(sf::Color::White);
        aptitudeManiabilite2[x].setCharacterSize(15);
        aptitudeManiabilite2[x].setPosition(sf::Vector2f(250 + (10* x) ,155));
    }

    for(int x(0); x < 5; x++)
    {
        aptitudeImpact2[x].setFont(font);
        aptitudeImpact2[x].setColor(sf::Color::White);
        aptitudeImpact2[x].setCharacterSize(15);
        aptitudeImpact2[x].setPosition(sf::Vector2f(250 + (10* x) ,195));
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
        if (selectedItemIndex1 < 3)
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
        m_sound.stop();
        Scene* next_scene = new RaceScene(winner, loser, delta);
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
                  if (player1->getMoney() >= 100)
                {
                    player1->setVitesseMax_m(++selectedStatVitesse1);
                    aptitudeVitesse1[selectedStatVitesse1].setString("+");
                    Sleep(100);
                }
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
        if (selectedItemIndex2 < 3)
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
        Scene* next_scene = new RaceScene(winner, loser, delta);
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
    selectedStatImpact1 = ((int)player1->getPenetrationZombie_m());

    selectedStatVitesse2 = ((int)player2->getVitesseMax_m());
    selectedStatAcceleration2 = ((int)player2->getAcceleration_m());
    selectedStatManiabilite2 = ((int)player2->getManiabilite_m());
    selectedStatImpact2 = ((int)player2->getPenetrationZombie_m());

    int tempsActuel = horlogeDebutStats.getElapsedTime().asMilliseconds();
    int monTempsRestant = (m_time_difference - tempsActuel) / 1000;

    std::stringstream ss;
    ss << monTempsRestant;
    string tempsRestant = ss.str();

    compteur.setString("Temps restant : " + tempsRestant);

    if(tempsActuel >= m_time_difference)
    {
        m_sound.stop();
        Scene* next_scene = new RaceScene(winner, loser, delta);
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
       window.draw((aptitudeImpact1[i]));
   }


    for (int i = 0; i < 6; i++)
    {
        window.draw(aptitude1[i]);
        window.draw(cash[i]);
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
       window.draw((aptitudeImpact2[i]));
   }


    for (int i = 0; i < 6; i++)
    {
        window.draw(aptitude2[i]);
        window.draw(cash[i]);
    }


    window.display();

}
