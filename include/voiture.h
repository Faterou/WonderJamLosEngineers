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

        float money;
        int petrole;

        float m_vitesse_courante;
        float m_vitesse_max;
        float m_acceleration;
        float m_maniabilite;
        float m_penetrationZombie;

        float m_vitesse_max_m;
        float m_acceleration_m;
        float m_maniabilite_m;
        float m_penetrationZombie_m;


        sf::Vector2f getHeading();

    public:
        Voiture(std::string nomPhoto);
        virtual ~Voiture();

        void set_vitesse_courante(float v){ m_vitesse_courante = v;}
        float get_vitesse_courante(){return m_vitesse_courante;}
        void miseAJourVoiture();

        void setVitesse_max(float vitesse);
        float getVitesse_max();

        void setAcceleration(float acceleration);
        float getAcceleration();

        void setManiabilite(float maniabilite);
        float getManiabilite();


        void setPenetrationZombie(float penetrationZombie);
        float getPenetrationZombie();

        void setVitesseMax_m(float vitesseMax);
        float getVitesseMax_m();

        void setAcceleration_m(float acceleration);
        float getAcceleration_m();

        void setManiabilite_m(float maniabilite);
        float getManiabilite_m();

        void setPenetrationZombie_m(float penetrationZombie);
        float getPenetrationZombie_m();

        void setMoney(float newAmount) {money = newAmount;};
        float getMoney() {return money;};

        void setPetrole(int newAmount) {petrole = newAmount;};
        int getPetrole() {return petrole;};

        void moveForward();
        void moveBackward();
        void rotateLeft();
        void rotateRight();
        void move();
        void idle();

        virtual void onCollision(GameObject*);
};

#endif // VOITURE_H
