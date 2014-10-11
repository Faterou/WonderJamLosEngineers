#ifndef VOITURE_H
#define VOITURE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <windows.h>
#include "GameObject.h"

extern sf::RenderWindow window;

class voiture : public GameObject
{
    private:

        float m_vitesse;
        float m_acceleration;
        float m_maniabilite;
        float m_suspension;
        float m_machineEssence;
        float m_penetrationZombie;

    public:
        voiture(std::string nomPhoto);
        virtual ~voiture();

        void setVitesse(float vitesse);
        float getVitesse();

        void setAcceleration(float acceleration);
        float getAcceleration();

        void setManiabilite(float maniabilite);
        float getManiabilite();

        void setSuspension(float suspension);
        float getSuspension();

        void setMachineEssence(float machineEssence);
        float getMachineEssence();

        void setPenetrationZombie(float penetrationZombie);
        float getPenetrationZombie();
};

#endif // VOITURE_H
