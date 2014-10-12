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

        int GetPressedItem() { return selectedItemIndex; }
    protected:
    private:
        int selectedItemIndex = 0;
        int selectedStatVitesse;
        int selectedStatAcceleration;
        int selectedStatManiabilite;
        int selectedStatGenerateurDePetrole;
        int selectedStatSuspension;
        int selectedStatImpact;

        sf::View view_player1;
        sf::View view_player2;

        sf::Font font;
        sf::Text compteur;
        sf::Text aptitude[6];
        sf::Text aptitudeVitesse[20];
        sf::Text aptitudeAcceleration[20];
        sf::Text aptitudeManiabilite[20];
        sf::Text aptitudeGenerationDePetrole[20];
        sf::Text aptitudeSuspension[20];
        sf::Text aptitudeImpact[20];
        sf::Text barre[20];

        sf::Clock horlogeDebutStats;
        int m_time_difference;



};

#endif // STATSSCENE_H
