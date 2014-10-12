#ifndef STATSSCENE_H
#define STATSSCENE_H

#include <Scene.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include "voiture.h"

#define MAX_NUMBER_OF_ITEMS 4

extern Voiture* player1;
extern Voiture* player2;

class StatsScene : public Scene
{
    public:
        StatsScene(GameObject winner, GameObject loser, int time_difference);
        virtual ~StatsScene();

        virtual void inputs();
        virtual void update();
        virtual void draw();
        void afficherStats();


    protected:
    private:
        int selectedItemIndex1 = 0;
        int selectedStatVitesse1 = 0;
        int selectedStatAcceleration1 = 0;
        int selectedStatManiabilite1 = 0;
        int selectedStatImpact1 = 0;

        int selectedItemIndex2 = 0;
        int selectedStatVitesse2 = 0;
        int selectedStatAcceleration2 = 0;
        int selectedStatManiabilite2 = 0;
        int selectedStatImpact2 = 0;

        sf::View view_player1;
        sf::View view_player2;

        sf::Font font;
        sf::Text compteur;
        sf::Text aptitude1[4];
        sf::Text aptitudeVitesse1[20];
        sf::Text aptitudeAcceleration1[20];
        sf::Text aptitudeManiabilite1[20];
        sf::Text aptitudeImpact1[20];
        sf::Text barre1[20];

        sf::Text aptitude2[4];
        sf::Text aptitudeVitesse2[20];
        sf::Text aptitudeAcceleration2[20];
        sf::Text aptitudeManiabilite2[20];
        sf::Text aptitudeImpact2[20];
        sf::Text barre2[20];

        sf::Clock horlogeDebutStats;
        int m_time_difference;



};

#endif // STATSSCENE_H
