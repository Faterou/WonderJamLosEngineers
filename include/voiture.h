#ifndef VOITURE_H
#define VOITURE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <windows.h>

static sf::RenderWindow window(sf::VideoMode(750, 750), "SFML works!");

class voiture
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        float m_vitesse;
        float m_acceleration;
        float m_maniabilite;
        float m_suspension;
        float m_machineEssence;
        float m_penetrationZombie;

    public:
        voiture(std::string nomPhoto);
        virtual ~voiture();
        void drawCar();

        sf::Texture getTexture();
        void setTexture(std::string nomTexture);

        sf::Sprite* getSprite();
        void setSprite(std::string nomSprite);

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
