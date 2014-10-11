#include "voiture.h"
#include <SFML/Graphics.hpp>
#include <windows.h>

voiture::voiture(std::string nomPhoto) : GameObject(sf::Sprite(),CAR)
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

voiture::~voiture()
{
    //dtor
}


void voiture::setVitesse(float vitesse)
{
    m_vitesse = vitesse;
}
float voiture::getVitesse()
{
    return m_vitesse;
}

void voiture::setAcceleration(float acceleration)
{
    m_acceleration = acceleration;
}
float voiture::getAcceleration()
{
    return m_acceleration;
}

void voiture::setManiabilite(float maniabilite)
{
    m_maniabilite = maniabilite;
}
float voiture::getManiabilite()
{
    return m_maniabilite;
}

void voiture::setSuspension(float suspension)
{

}
float voiture::getSuspension()
{
    return m_suspension;
}

void voiture::setMachineEssence(float machineEssence)
{
    m_machineEssence = machineEssence;
}
float voiture::getMachineEssence()
{
    return m_machineEssence;
}

void voiture::setPenetrationZombie(float penetrationZombie)
{
    m_penetrationZombie = penetrationZombie;
}
float voiture::getPenetrationZombie()
{
    return m_penetrationZombie;
}

