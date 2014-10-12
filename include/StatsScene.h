#ifndef STATSSCENE_H
#define STATSSCENE_H

#include <Scene.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 4

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
        int selectedStatVitesse = 0;
        int selectedStatAcceleration = 0;
        int selectedStatManiabilite = 0;
        int selectedStatGenerateurDePetrole = 0;
        int selectedStatSuspension = 0;
        int selectedStatImpact = 0;

        sf::Font font;
        sf::Text aptitude[6];
        sf::Text aptitudeVitesse[20];
        sf::Text aptitudeAcceleration[20];
        sf::Text aptitudeManiabilite[20];
        sf::Text aptitudeGenerationDePetrole[20];
        sf::Text aptitudeSuspension[20];
        sf::Text aptitudeImpact[20];
        sf::Text barre[20];



};

#endif // STATSSCENE_H
