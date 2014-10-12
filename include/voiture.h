#ifndef VOITURE_H
#define VOITURE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <windows.h>
#include "GameObject.h"

extern sf::RenderWindow window;

class Voiture : public GameObject
{
    private:

        float m_vitesse_courante;
        float m_vitesse_max;
        float m_acceleration;
        float m_maniabilite;
        float m_suspension;
        float m_machineEssence;
        float m_penetrationZombie;

        sf::Vector2f getHeading();

    public:
        Voiture(std::string nomPhoto);
        virtual ~Voiture();

        void set_vitesse_courante(float);
        float get_vitesse_courante();

        void setVitesse_max(float vitesse);
        float getVitesse_max();

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

        void moveForward();
        void moveBackward();
        void rotateLeft();
        void rotateRight();

        virtual void onCollision(GameObject*);
};

#endif // VOITURE_H
