#include "Voiture.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cmath>
using namespace std;

Voiture::Voiture(std::string nomPhoto) : GameObject(sf::Sprite(),CAR)
{
    m_vitesse = 1;
    m_acceleration = 1;
    m_maniabilite = 1;
    m_suspension = 1;
    m_machineEssence = 1;
    m_penetrationZombie = 1;

    if (!texture.loadFromFile(nomPhoto))
    {
        std::cout << "Erreur chargement de personnage" << std::endl;
    }

    sprite.setTexture(texture);

}

Voiture::~Voiture()
{
    //dtor
}

sf::Vector2f Voiture::getHeading()
{
    float teta = GameObject::getSprite()->getRotation() + 90;
    float x = cos(teta*M_PI/180);
    float y = sin(teta*M_PI/180);
    return sf::Vector2f(x,y);
}

void Voiture::setVitesse(float vitesse)
{
    m_vitesse = vitesse;
}
float Voiture::getVitesse()
{
    return m_vitesse;
}

void Voiture::setAcceleration(float acceleration)
{
    m_acceleration = acceleration;
}
float Voiture::getAcceleration()
{
    return m_acceleration;
}

void Voiture::setManiabilite(float maniabilite)
{
    m_maniabilite = maniabilite;
}
float Voiture::getManiabilite()
{
    return m_maniabilite;
}

void Voiture::setSuspension(float suspension)
{

}
float Voiture::getSuspension()
{
    return m_suspension;
}

void Voiture::setMachineEssence(float machineEssence)
{
    m_machineEssence = machineEssence;
}
float Voiture::getMachineEssence()
{
    return m_machineEssence;
}

void Voiture::setPenetrationZombie(float penetrationZombie)
{
    m_penetrationZombie = penetrationZombie;
}
float Voiture::getPenetrationZombie()
{
    return m_penetrationZombie;
}

